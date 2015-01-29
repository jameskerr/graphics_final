#ifndef MAC //if not MAC
#include <GL\glut.h>
#else // MAC includes below
#include <GLUT/glut.h>
#endif

#include "car.h"

void Car::display() {
  tick();  // Sets the state for this frame

  GLfloat sample_rate = 0.01;
  
  // The tires
  tire(1, car_length, 0, car_width * -1,        0, wheel_turn_angle);  // Front left
  tire(1, car_length, 0, car_width * 1,         0, wheel_turn_angle);  // Front right

  tire(2, car_length * -1, 0, car_width * -1.3, wheel_rotation_angle, wheel_turn_angle * -0.5 );  // Back Left
  tire(2, car_length * -1, 0, car_width * 1.3,  wheel_rotation_angle, wheel_turn_angle * -0.5);  // Back Right
  

  // The Triangle part of the car
  glPushMatrix();
    glBegin(GL_TRIANGLE_STRIP);
      glColor3f(0.3, 0.1, 0.3);
      for (GLfloat i = 0; i <= 0.2; i += 0.01) {
        glVertex3f(car_length * 1 *(1.8 - i), i, car_width *  1 *(0 - i));
        glVertex3f(car_length * -1.3,  i, car_width * -1);
        glVertex3f(car_length * -1.3,  i, car_width *  1);
        glVertex3f(car_length * 1 *(1.8 - i), i, car_width * -1 *(0 - i));
      }
    glEnd();
  glPopMatrix();

  // Headlight 1
  glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(car_length, 0.1, 0.2);
    glutSolidCube(0.1);
    glRotatef(270, 0, 1, 0);
    glTranslatef(0, 0, -0.1);
    glColor3f(1, 1, 0);
    glutSolidCone(0.05, 0.1, 20, 20);
  glPopMatrix();

  // Headlight 2
  glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(car_length, 0.1, -0.2);
    glutSolidCube(0.1);
    glRotatef(270, 0, 1, 0);
    glTranslatef(0, 0, -0.1);
    glColor3f(1, 1, 0);
    glutSolidCone(0.05, 0.1, 20, 20);
  glPopMatrix();

  // The Axles
  glPushMatrix();
    glBegin(GL_POINTS);
      glPointSize(20);
      glColor3f(0.1, 0.1, 0.1);
      for(GLfloat z = car_width * -1; z <= car_width; z += sample_rate) glVertex3f(car_length, 0, z);
      for(GLfloat z = car_width * -1; z <= car_width; z += sample_rate) glVertex3f(car_length * -1, 0, z);
    glEnd();
  glPopMatrix();

  // The cockpit
  glPushMatrix();
    glColor3f(0.4,0.4,0.4);
    glPointSize(10);
    glTranslatef(-0.3, 0, 0);
    for (GLfloat y = 0.2; y <= 0.4; y += 0.01 ) {      
      glBegin(GL_LINE_LOOP);
        glVertex3f(car_length * -1.3 , y, car_width * 1);
        glVertex3f(car_length * -1.3, y, car_width * -1);
        glVertex3f(car_length * -0.5 , y - 0.2, car_width * -0.8);
        glVertex3f(car_length * -0.5 , y - 0.2, car_width * 0.8);
      glEnd();
      }
      glBegin(GL_POLYGON);
        glVertex3f(car_length * -1.3 , 0.4, car_width * 1);
        glVertex3f(car_length * -1.3, 0.4, car_width * -1);
        glVertex3f(car_length * -0.5 , 0.2, car_width * -0.8);
        glVertex3f(car_length * -0.5 , 0.2, car_width * 0.8);
      glEnd(); 
  glPopMatrix();

  // The motor
  glPushMatrix();
    glColor3f(0.6,0.2,0.2);
    glTranslatef(-0.57, 0.18, 0);
    for (int motor = 0; motor < 40; ++motor) {
      glTranslatef(0.01, 0, 0);
      glutSolidSphere(0.11, 2, 60);
      glutSolidCube(0.15);
    }
    glTranslatef(0.1, 0, 0);
  glPopMatrix();

  // The teapot
  glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslatef(car_length + 0.2, 0.26, 0);
    glutSolidTeapot(0.06);
  glPopMatrix();

  // The dude
  glPushMatrix();
    // Body
    glColor3f(0.4, 0.2, 0.1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0.2 ,0 ,0);
    glRotatef(wheel_turn_angle * 0.5, 1, 0, 0);
    glRotatef(wheel_turn_angle * 1.5, 0, 0, 1);
    
    glutSolidCone(0.1, 0.45, 20, 1);
    // Head

    glColor3f(0.98, 0.75, 0.5);
    glTranslatef(0, 0, 0.38);
    glColor3f(0.98, 0.75, 0.5);
    glutSolidSphere(0.075, 40, 40);

    glPushMatrix();
      glColor3f(0.1, 0.9, 0.1);
      glScalef(0.15,0.15,0.15);
      glRotatef(-60, 0, 1, 0);
      glutSolidCone(0.2, 0.8, 10, 1.0);
      glRotatef(20, 0, 1, 0);
      glutSolidCone(0.2, 0.8, 10, 1.0);
      glRotatef(20, 0, 1, 0);
      glutSolidCone(0.2, 0.8, 10, 1.0);
      glRotatef(20, 0, 1, 0);
      glutSolidCone(0.2, 0.8, 10, 1.0);
      glRotatef(20, 0, 1, 0);
      glutSolidCone(0.2, 0.8, 10, 1.0);
    glPopMatrix();

    // Goggles
    glColor3f(0.4, 0.2, 0.1);

    GLUquadric *quad;
    quad = gluNewQuadric();
    
    // Goggle eye 1
    glPushMatrix();
      glColor3f(0.4, 0.2, 0.1);
      glTranslatef(0, 0.028, 0);
      glPushMatrix();
        glRotatef(90, 0,1,0);
        gluCylinder(quad, 0.025, 0.025, 0.075, 15, 15);
      glPopMatrix();

      glColor3f(0.1, 0.1, 0.1);
      glTranslatef(0.075, 0, 0);
      glutSolidSphere(0.025, 2, 40);
    glPopMatrix();

    // Goggle eye 2
    glPushMatrix();
      glColor3f(0.4, 0.2, 0.1);
      glTranslatef(0, -0.028, 0);
      glPushMatrix();
        glRotatef(90, 0,1,0);
        gluCylinder(quad, 0.025, 0.025, 0.075, 15, 15);
      glPopMatrix();
      glTranslatef(0.075, 0, 0);
      glColor3f(0.1, 0.1, 0.1);
      glutSolidSphere(0.025, 2, 40);
    glPopMatrix();

    // The strap
    glColor3f(0.4, 0.2, 0.1);
    glutSolidTorus(0.03, 0.046, 40, 40);
  glPopMatrix();

  // The steering wheel
  glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, -0.03, 0.3);

    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(0, 0.3, 0);
    glutSolidTorus(0.01, 0.07, 40, 40);
    glLineWidth(7);
    glBegin(GL_LINES);
      glVertex3f(0, 0, 0);
      glVertex3f(0, -0.075, 0);

      glVertex3f(0,0,0);
      glVertex3f(0.05, 0.05, 0);

      glVertex3f(0,0,0);
      glVertex3f(-0.05, 0.05, 0);
    glEnd();

    glColor3f(1, 1, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
      glVertex3f(0, 0, 0);
    glEnd();
  glPopMatrix();

}

void Car::tire(GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat angle, GLfloat turn) {
  glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(x, y, z);
    glRotatef(angle, 1, 0, 0);
    glRotatef(turn, 0, 1, 0);
    glRotatef(wheel_rotation_speed, 0, 0, 1);
    glutWireTorus(tire_inner_radius * size, tire_outer_radius * size, tire_sides, tire_rings);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.05 * size, 40, 40);
    glColor3f(0.9, 0.3, 0.3);
    glutWireSphere(0.07 * size, 15, 15);
  glPopMatrix();
}

void Car::tick() {
  if (is_moving_forward) {
    wheel_rotation_speed -= 2.5;
  } else if (is_moving_backward) {
    wheel_rotation_speed += 2.5;
  }

  // Left Turn
  if (is_turning_left) {
    if (wheel_rotation_angle < 20.0) {
       wheel_rotation_angle += 5.0;
       wheel_turn_angle     += 5.0;
    } else {
      is_turning_left = false;
      go_strait = true;
    }
  }

  // Right Turn
  if (is_turning_right) {
    if (wheel_rotation_angle > -20.0) {
      wheel_rotation_angle -= 5.0;
      wheel_turn_angle     -= 5.0;
    } else {
      is_turning_right = false;
      go_strait = true;
    }
  }

  if (go_strait) {
    if (wheel_rotation_angle < 0) {
      wheel_rotation_angle += 5.0;
      wheel_turn_angle     += 5.0;
    } else if (wheel_rotation_angle > 0) {
      wheel_rotation_angle -= 5.0;
      wheel_turn_angle     -= 5.0;
    }
  }
}

void Car::turnLeft() {
  is_turning_left = true;
  is_turning_right = false;
  go_strait = false;
}

void Car::turnRight() {
  is_turning_right = true;
  is_turning_left = false;
  go_strait = false;
}

void Car::moveForward() {
  is_moving_forward = true;
  is_moving_backward = false;
}

void Car::moveBackward() {
  is_moving_backward = true;
  is_moving_forward = false;
}

void Car::goStrait() {
  is_turning_right = false;
  is_turning_left = false;
  go_strait = true;
}

void Car::stop() {
  is_moving_backward = false;
  is_moving_forward = false;
  is_turning_right = false;
  is_turning_left = false;
  go_strait = true;
}