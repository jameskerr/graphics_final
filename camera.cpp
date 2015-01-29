#include <math.h>
#include "camera.h"

void Camera::refresh() {
	xPosition = x;
	zPosition = z;
	xFocus    = x + lx;
	zFocus    = z + lz;
}

void Camera::driveForward() {
	x += lx * fraction;
	z += lz * fraction;
	refresh();
}


void Camera::driveBackward() {
	x -= lx * fraction;
	z -= lz * fraction;
	refresh();
}

//rotates the point you are looking at around the "camera"
void Camera::turnRight()
{
	angle += 0.15f;
	lx = sin(angle);
	lz = -cos(angle);
	refresh();
}

//rotates the point you are looking at around the "camera"
void Camera::turnLeft()
{
	angle -= 0.15f;
	lx = sin(angle);
	lz = -cos(angle);
	refresh();
}