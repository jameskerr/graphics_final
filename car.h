class Car {
public:
  // Constructor

  // Display
  void display();
  bool moving();
  void setMoving(bool moving);
  void moveForward();
  void turnLeft();
  void turnRight();
  void goStrait();
  void tick();
  void menu(int item);

private:
  GLfloat car_length = 0.5; // From origin
  GLfloat car_width  = 0.3; // From origin
  GLfloat tire_inner_radius = 0.05;
  GLfloat tire_outer_radius = 0.1;
  GLint   tire_sides = 20;
  GLint   tire_rings = 50;

  bool is_moving = true;
  GLfloat wheel_rotation_speed = 0.0;
  GLfloat wheel_rotation_angle = 0.0;
  GLfloat wheel_turn_angle     = 0.0;

  bool turning_left  = false;
  bool turning_right = false;
  bool go_strait = true;

  void tire(GLfloat size, GLfloat x, GLfloat y, GLfloat z, GLfloat angle, GLfloat turn);

};