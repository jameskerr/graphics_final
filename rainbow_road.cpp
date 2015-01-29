#ifndef MAC //if not MAC
#include <GL\glut.h>
#else // MAC includes below
#include <GLUT/glut.h>
#endif

#include "car.h"

GLfloat width = 600.0;
GLfloat height = 600.0;

GLfloat rotate_around_x = 1.5;
GLfloat rotate_around_y = 1.5;
GLfloat rotate_around_z = 1.5;
Car car;

/********************
::: MAIN FUNCTION :::
********************/


void display() {
  //glLoadIdentity();
  // gluLookAt(rotate_around_x, rotate_around_y, rotate_around_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glPushMatrix();
    glRotatef(rotate_around_x, 1, 0, 0);
    glRotatef(rotate_around_y, 0, 1, 0);
    glRotatef(rotate_around_z, 0, 0, 1);
    car.display();

    glPopMatrix();
    
  glutSwapBuffers();
}

void reshape (int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(50, 1, 1, 40);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void idle() {
  // rotate_around_x += 0.01;
   rotate_around_y += 0.5;
   if (car.moving()) {
    car.moveForward();
   }
  // rotate_around_z += 0.01;
  // gluLookAt(rotate_around_x, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glutPostRedisplay();
}

void menu(int item) {
  car.menu(item);
}

void init() {
  GLfloat ambient_light[]    = { 0.2, 0.2, 0.2, 1.0 };
  GLfloat diffuse_light[]    = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular_light[]   = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position_0[] = { 0.0, 0.0, 1.0, 0.0 };


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
}

void specialKeys(int key, int x, int y) {
  if (key == GLUT_KEY_RIGHT)
    car.turnRight();
  
  else if (key == GLUT_KEY_LEFT)
    car.turnLeft();

  else
    car.goStrait();
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