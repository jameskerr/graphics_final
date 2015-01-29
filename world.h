#include <GlUT/glut.h>
#include "./soil/SOIL.h"

class World {
public:

  
  void init();
  void display();
  void idle();

private:
  GLuint rainbowSides;
  GLuint rainbowFloor;
  GLuint dinosaurSides;
  GLuint dinosaurFloor;
  GLuint koopaSides;
  GLuint koopaFloor;
  GLuint yellowBrickSides;
  GLuint yellowBrickFloor;

  bool rainbowRoad = true;
  bool dinosaur = false;
  bool koopa = false;
  bool yellowBrick = false;
};