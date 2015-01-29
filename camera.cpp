#include "camera.h"
#include <math.h>

void Camera::init(double x, double y, double z, double fx, double fy, double fz, double ux, double uy, double uz) {
	xPosition = x;
	yPosition = y;
	zPosition = z;

	xFocus = fx; 
	yFocus = fy;
	zFocus = fz;

	xUp = ux;
	yUp = uy;
	zUp = uz;
}

void Camera::driveForward() {
	double xDir = xFocus-xPosition;
	double yDir = yFocus-yPosition;
	double zDir = zFocus-zPosition;
	double scale = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	if (scale<0.5) { //So that you cannot "move" through the point
    xFocus+=(xDir / scale)*10;
    yFocus+=(yDir / scale)*10;
    zFocus+=(zDir / scale)*10;
   }
  xPosition += (xDir / scale)*.5;
  yPosition += (yDir / scale)*.5;
  zPosition += (zDir / scale)*.5;
}


void Camera::driveBackward() {
	double xDir = xFocus-xPosition;
	double yDir = yFocus-yPosition;
	double zDir = zFocus-zPosition;
	double scale = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	xPosition -= (xDir / scale)*.5;
	yPosition -= (yDir / scale)*.5;
	zPosition -= (zDir / scale)*.5;
}

void Camera::cameraUp()
{
	double scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
	xPosition += (xUp*.5);
	yPosition += (yUp*.5);
	zPosition += (zUp*.5);
	xFocus += (xUp*.5);
	yFocus += (yUp*.5);
	zFocus += (zUp*.5);
}

//shift the camera away from the "up" vector
void Camera::cameraDown()
{
	double scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
	xPosition -= (xUp*.5);
	yPosition -= (yUp*.5);
	zPosition -= (zUp*.5);
	xFocus -= (xUp*.5);
	yFocus -= (yUp*.5);
	zFocus -= (zUp*.5);
}

//rotates the camera around the point you are looking at
void Camera::revolveLeft()
{
	double origRadius = sqrt((xPosition-xFocus)*(xPosition-xFocus)+(yPosition-yFocus)*(yPosition-yFocus)+(zPosition-zFocus)*(zPosition-zFocus));
	double xDir = (xPosition-xFocus);
	double yDir = (yPosition-yFocus);
	double zDir = (zPosition-zFocus);
	double xOrtho = yUp*zDir-zUp*yDir;
	double yOrtho = zUp*xDir-xUp*zDir;
	double zOrtho = xUp*yDir-yUp*xDir;
	double scale = sqrt(xOrtho*xOrtho+yOrtho*yOrtho+zOrtho*zOrtho);
	xOrtho /= scale;
	yOrtho /= scale;
	zOrtho /= scale;
	xDir -= (xOrtho*.5);
	yDir -= (yOrtho*.5);
	zDir -= (zOrtho*.5);
	double radius = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xOrtho = yUp*zDir-zUp*yDir;
	yOrtho = zUp*xDir-xUp*zDir;
	zOrtho = xUp*yDir-yUp*xDir;
	xUp = zOrtho*yDir-yOrtho*zDir;
	yUp = xOrtho*zDir-zOrtho*xDir;
	zUp = yOrtho*xDir-xOrtho*yDir;
	xPosition = xDir+xFocus;
	yPosition = yDir+yFocus;
	zPosition = zDir+zFocus;
	scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
}

//rotates the camera around the point you are looking at
void Camera::revolveRight()
{
	double origRadius = sqrt((xPosition-xFocus)*(xPosition-xFocus)+(yPosition-yFocus)*(yPosition-yFocus)+(zPosition-zFocus)*(zPosition-zFocus));
	double xDir = (xPosition-xFocus);
	double yDir = (yPosition-yFocus);
	double zDir = (zPosition-zFocus);
	double xOrtho = yUp*zDir-zUp*yDir;
	double yOrtho = zUp*xDir-xUp*zDir;
	double zOrtho = xUp*yDir-yUp*xDir;
	double scale = sqrt(xOrtho*xOrtho+yOrtho*yOrtho+zOrtho*zOrtho);
	xOrtho /= scale;
	yOrtho /= scale;
	zOrtho /= scale;
	xDir += (xOrtho*.5);
	yDir += (yOrtho*.5);
	zDir += (zOrtho*.5);
	double radius = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xOrtho = yUp*zDir-zUp*yDir;
	yOrtho = zUp*xDir-xUp*zDir;
	zOrtho = xUp*yDir-yUp*xDir;
	xUp = zOrtho*yDir-yOrtho*zDir;
	yUp = xOrtho*zDir-zOrtho*xDir;
	zUp = yOrtho*xDir-xOrtho*yDir;
	xPosition = xDir+xFocus;
	yPosition = yDir+yFocus;
	zPosition = zDir+zFocus;
	scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
}

//rotates the point you are looking at around the "camera"
void Camera::turnRight()
{
	double origRadius = sqrt((xPosition-xFocus)*(xPosition-xFocus)+(yPosition-yFocus)*(yPosition-yFocus)+(zPosition-zFocus)*(zPosition-zFocus));
	double xDir = -(xPosition-xFocus);
	double yDir = -(yPosition-yFocus);
	double zDir = -(zPosition-zFocus);
	double xOrtho = yUp*zDir-zUp*yDir;
	double yOrtho = zUp*xDir-xUp*zDir;
	double zOrtho = xUp*yDir-yUp*xDir;
	double scale = sqrt(xOrtho*xOrtho+yOrtho*yOrtho+zOrtho*zOrtho);
	xOrtho /= scale;
	yOrtho /= scale;
	zOrtho /= scale;
	xDir -= (xOrtho*.5);
	yDir -= (yOrtho*.5);
	zDir -= (zOrtho*.5);
	double radius = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xOrtho = yUp*zDir-zUp*yDir;
	yOrtho = zUp*xDir-xUp*zDir;
	zOrtho = xUp*yDir-yUp*xDir;
	xUp = zOrtho*yDir-yOrtho*zDir;
	yUp = xOrtho*zDir-zOrtho*xDir;
	zUp = yOrtho*xDir-xOrtho*yDir;
	xFocus = xDir+xPosition;
	yFocus = yDir+yPosition;
	zFocus = zDir+zPosition;
	scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
}

//rotates the point you are looking at around the "camera"
void Camera::turnLeft()
{
	double origRadius = sqrt((xPosition-xFocus)*(xPosition-xFocus)+(yPosition-yFocus)*(yPosition-yFocus)+(zPosition-zFocus)*(zPosition-zFocus));
	double xDir = -(xPosition-xFocus);
	double yDir = -(yPosition-yFocus);
	double zDir = -(zPosition-zFocus);
	double xOrtho = yUp*zDir-zUp*yDir;
	double yOrtho = zUp*xDir-xUp*zDir;
	double zOrtho = xUp*yDir-yUp*xDir;
	double scale = sqrt(xOrtho*xOrtho+yOrtho*yOrtho+zOrtho*zOrtho);
	xOrtho /= scale;
	yOrtho /= scale;
	zOrtho /= scale;
	xDir += (xOrtho*.5);
	yDir += (yOrtho*.5);
	zDir += (zOrtho*.5);
	double radius = sqrt(xDir*xDir+yDir*yDir+zDir*zDir);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xDir *= (origRadius/radius);
	xOrtho = yUp*zDir-zUp*yDir;
	yOrtho = zUp*xDir-xUp*zDir;
	zOrtho = xUp*yDir-yUp*xDir;
	xUp = zOrtho*yDir-yOrtho*zDir;
	yUp = xOrtho*zDir-zOrtho*xDir;
	zUp = yOrtho*xDir-xOrtho*yDir;
	xFocus = xDir+xPosition;
	yFocus = yDir+yPosition;
	zFocus = zDir+zPosition;
	scale = sqrt(xUp*xUp+yUp*yUp+zUp*zUp);
	xUp /= scale;
	yUp /= scale;
	zUp /= scale;
}