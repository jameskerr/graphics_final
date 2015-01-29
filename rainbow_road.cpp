#ifndef MAC //if not MAC
#include <GL\glut.h>
#else // MAC includes below
#include <GLUT/glut.h>
#endif

#include <iostream>
#include "world.h"
#include "car.h"
#include "camera.h"

using namespace std;


GLfloat width = 800.0;
GLfloat height = 800.0;

GLfloat rotate_around_x = 0;
GLfloat rotate_around_y = 0;
GLfloat rotate_around_z = 0;

GLfloat world_scale = 10;
GLfloat world_ground_offset = -9.95 * world_scale;
GLfloat world_rotate_angle = 0;

Car car;
World world;
Camera camera;

/********************
::: MAIN FUNCTION :::
********************/


void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);

  glLoadIdentity();
  
  glPushMatrix();
    
    //glTranslatef(0, world_ground_offset, 0);
    glTranslatef(0, 0, -3);
    glRotatef(90, 0, 1, 0);
    //glRotatef(20, 0, 0, 1);
    car.display();
  glPopMatrix();

  gluLookAt(camera.xPosition, camera.yPosition, camera.zPosition, camera.xFocus, camera.yFocus, camera.zFocus, camera.xUp, camera.yUp, camera.zUp);

  
  glPushMatrix();
    glScalef(world_scale, world_scale, world_scale);
    glColor3f(1.0, 1.0, 1.0);
    world.display();
  glPopMatrix();
    

    
    // Rotate the world to which ever "floor I am on"


  glPopMatrix();
    
  glutSwapBuffers();
}

void reshape (int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(50, 1, 1, 400);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  camera.init(-3.0, 0.0 + world_ground_offset, 0, 
               2.0, 0.0 + world_ground_offset, 0, 
               0.0, 1.0, 0.0);
  camera.turnRight();
}

void idle() {
   //camera.driveForward();
   if (car.moving()) {
    car.moveForward();
   }
  glutPostRedisplay();
}

void menu(int item) {
  car.menu(item);
}

void init() {
  GLfloat ambient_light[]    = { 0.2, 0.2, 0.2, 1.0 };
  GLfloat diffuse_light[]    = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular_light[]   = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position_0[] = { 0.0, 0.0, -1.0, 0.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
  glShadeModel(GL_SMOOTH);
  glClearColor(0.8, 0.8, 0.8, 1.0);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glEnable(GL_COLOR_MATERIAL);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  world.init();
}

void specialKeys(int key, int x, int y) {
  if (key == GLUT_KEY_RIGHT) {
    camera.turnRight();
    car.turnRight();
  }
  
  else if (key == GLUT_KEY_LEFT) {
    camera.turnLeft();
    car.turnLeft();
  }

  else if (key == GLUT_KEY_UP) {
    camera.driveForward();
    car.goStrait();
  }
  else if (key == GLUT_KEY_DOWN) {
    camera.driveBackward();
    car.goStrait();
  }
}


int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(0,0);
  glutCreateWindow("A Car");

  init();
  glutCreateMenu(menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutAddMenuEntry("Turn Left",   0);
  glutAddMenuEntry("Turn Right",  1);
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;
}