class Car {
public:
  // Constructor

  // Display
  void display();
  void tick();

  void moveForward();
  void moveBackward();
  void turnLeft();
  void turnRight();
  void goStrait();
  void stop();

  bool is_turning_left  = false;
  bool is_turning_right = false;
  bool is_moving_forward = false;
  bool is_moving_backward = false;
  bool go_strait = true;

private:
  GLfloat car_length = 0.5; // From origin
  GLfloat car_width  = 0.3; // From origin
  GLfloat tire_inner_radius = 0.05;
  GLfloat tire_outer_radius = 0.1;
  GLint   tire_sides = 20;
  GLint   tire_rings = 50;

  GLfloat wheel_rotation_speed = 0.0;
  GLfloat wheel_rotation_angle = 0.0;
  GLfloat wheel_turn_angle     = 0.0;

  void tire(GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat angle, GLfloat turn);

};