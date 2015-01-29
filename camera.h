/*
 * A big thank you to this website
 * http://www.lighthouse3d.com/tutorials/glut-tutorial/keyboard-example-moving-around-the-world/
 */

class Camera {
public:
  void refresh();
  void driveForward();
  void driveBackward();
  void turnLeft();
  void turnRight();

  float angle;
  float lx; 
  float lz;
  float x;
  float z;
  float fraction;

  float xPosition;
  float yPosition;
  float zPosition;
  float xFocus;
  float yFocus;
  float zFocus;
  float xUp; 
  float yUp; 
  float zUp; 
};