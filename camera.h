
class Camera {
public:
  void init(double x, double y, double z, double fx, double fy, double fz, double ux, double uy, double uz);
  void driveForward();
  void driveBackward();
  void cameraUp();
  void cameraDown();
  void revolveLeft();
  void revolveRight();
  void turnLeft();
  void turnRight();

  double xPosition = 0.0;
  double yPosition = 0.0;
  double zPosition = -5.0;

  double xFocus = 0.0;
  double yFocus = 0.0;
  double zFocus = -1.0;

  double xUp = 0.0;
  double yUp = 1.0;
  double zUp = 0.0;
};