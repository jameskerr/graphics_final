#ifndef MAC //if not MAC
#include <GL\glut.h>
#else // MAC includes below
#include <GLUT/glut.h>
#endif

#include <math.h>
#include <iostream>
#include "world.h"
#include "car.h"
#include "camera.h"

using namespace std;


GLfloat width = 800.0;
GLfloat height = 800.0;

GLfloat ambient_light[]    = { 0.2, 0.2, 0.2, 1.0 };
GLfloat diffuse_light[]    = { 1.0, 1.0, 1.0, 1.0 };
GLfloat specular_light[]   = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position_0[] = { 1.0, 0.0, 1.0, 0.0 };

GLfloat world_scale = 15;
GLfloat world_ground_offset = -9.95 * world_scale;
GLfloat world_rotate_angle = 0;

GLfloat rotate_threshold = world_scale * 10;

GLfloat rotate_x = 0;
GLfloat rotate_y = 0;
GLfloat rotate_z = 0;

GLfloat rotate_car_x = 0;
GLfloat rotate_car_y = 90;
GLfloat rotate_car_z = 30;

bool fly_mode = false;


Car car;
World world;
Camera camera;


/********************
::: MAIN FUNCTION :::
********************/

void display() {
  // Reset
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  // Render the car statically -- before the gluLookat() 
  glPushMatrix();
    glTranslatef(0, 0, -3);
    glRotatef(rotate_car_x, 0, 1, 0);
    glRotatef(rotate_car_y, 0, 1, 0);
    glRotatef(rotate_car_z, 0, 0, 1);
    car.display();
  glPopMatrix();

  // Position the camera
  gluLookAt(camera.xPosition, camera.yPosition, camera.zPosition, camera.xFocus, camera.yFocus, camera.zFocus, camera.xUp, camera.yUp, camera.zUp);
  
  // Adjust the lighting
  glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
  
  // Render the world
  glPushMatrix();
    glRotatef((rotate_x) * 0.8, 0.5, 0, 0);
    glRotatef((rotate_y) * 0.8, 0, 0.5, 0);
    glRotatef((rotate_z) * 0.8, 0, 0, 0.5);
    glScalef(world_scale, world_scale, world_scale);
    glColor3f(1.0, 1.0, 1.0);
    world.display();
  glPopMatrix();

  // Do it!
  glutSwapBuffers();
}

void reshape (int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(75, 1, 1, 800);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void rotateCube() {
  rotate_x += 0.08;
  rotate_y += 0.06;
  rotate_z += 0.03;
}

void reset() {
  camera.angle = 90.0;
  camera.lx    =  0.0f;
  camera.lz    = 1.0f;
  camera.x     = 0.0f;
  camera.z     = 5.0f;

  rotate_x =0;
  rotate_y =0;
  rotate_z =0;
  rotate_car_x = 0;
  rotate_car_y = 90;
  rotate_car_z = 30;
}

void spinCar() {
  rotate_car_x += 0.1;
  rotate_car_y += 0.3;
  rotate_car_z -= 0.2;
} 

void idle() {
  if (car.is_moving_forward) {
    camera.driveForward();
    cout << "-------" << endl;
    cout << "x: " << camera.xFocus << endl;
    cout << "y: " << camera.yFocus << endl;
    cout << "z: " << camera.zFocus << endl;
    cout << endl;
  } else if (car.is_moving_backward) {
    camera.driveBackward();
  }

  if (car.is_turning_left) {
    camera.turnLeft();
  } else if (car.is_turning_right) {
    camera.turnRight();
  }

  if (fly_mode) {
    rotateCube();  
    spinCar();
  }
  
  glutPostRedisplay();
}

void menu(int item) {
  if (item == 0) { // fly mode
    if (fly_mode) {
      fly_mode = false;
      reset();
    } else {
      fly_mode = true;
    }
  }
}

void init() {
  GLfloat ambient_light[]    = { 0.2, 0.2, 0.2, 1.0 };
  GLfloat diffuse_light[]    = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat specular_light[]   = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position_0[] = { 1.0, 0.0, 1.0, 0.0 };

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
  // angle of rotation for the camera direction
  reset();
  
  camera.fraction  = 1.0f;
  camera.xPosition = camera.x;
  camera.yPosition = 1 + world_ground_offset;  // Adjust for the world scaling
  camera.zPosition = camera.z;
  
  camera.xFocus = camera.x + camera.lx;
  camera.yFocus = 0.7 + world_ground_offset;
  camera.zFocus = camera.z + camera.lz;
  
  camera.xUp = 0.0;
  camera.yUp = 1.0;
  camera.zUp = 0.0;
}

void specialKeys(int key, int x, int y) {
  if (key == GLUT_KEY_RIGHT) {
    car.turnRight();
  }
  
  else if (key == GLUT_KEY_LEFT) {
    car.turnLeft();
  }

  else if (key == GLUT_KEY_UP) {
    car.goStrait();
    if (car.is_moving_backward){
      car.stop();
    } else {
      car.moveForward();  
    }
  }
  else if (key == GLUT_KEY_DOWN) {
    car.goStrait();
    if (car.is_moving_forward) {
      car.stop();
    } else {
      car.moveBackward();  
    }
  }
}

void keyboard(unsigned char key, int x, int y) {
  if (key == 'w') {
    rotate_x -= 1;
  }
  if (key == 's') {
    rotate_x +=1;
  }
  if (key == 'd') {
    rotate_z += 1;
  }
  if (key == 'a') {
    rotate_z -= 1;
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
  glutAddMenuEntry("Zero Gs!",   0);
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}