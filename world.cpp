#include "world.h"

void World::init() {
	    dinosaurFloor = SOIL_load_OGL_texture
		(
	     "DinosaurFloor.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    dinosaurSides = SOIL_load_OGL_texture
		(
	     "DinosaurSides.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    koopaFloor = SOIL_load_OGL_texture
		(
	     "KoopaFloor.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    koopaSides = SOIL_load_OGL_texture
		(
	     "KoopaSides.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    rainbowFloor = SOIL_load_OGL_texture
		(
	     "rainbowFloor.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    rainbowSides = SOIL_load_OGL_texture
		(
	     "RainbowSides.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    yellowBrickFloor = SOIL_load_OGL_texture
		(
	     "YellowBrickFloor.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
	    yellowBrickSides = SOIL_load_OGL_texture
		(
	     "YellowBrickSides.jpg",
	     SOIL_LOAD_AUTO,
	     SOIL_CREATE_NEW_ID,
	     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	     );
}

void World::display() {

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glEnable(GL_TEXTURE_2D);
	if(rainbowRoad == true)
	{
	    glBindTexture(GL_TEXTURE_2D, rainbowSides);
	}
	else if(koopa == true)
	{
	    glBindTexture(GL_TEXTURE_2D, koopaSides);
	}
	else if(dinosaur == true)
	{
	    glBindTexture(GL_TEXTURE_2D, dinosaurSides);
	}
	else if(yellowBrick == true)
	{
	    glBindTexture(GL_TEXTURE_2D, yellowBrickSides);
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D, rainbowSides);
	}
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  10.0f);  // Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  10.0f);  // Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f,  10.0f);  // Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f,  10.0f);  // Top Left Of The Texture and Quad
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  10.0f);  // Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  10.0f,  10.0f);  // Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -10.0f);  // Top Left Of The Texture and Quad
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -10.0f);  // Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -10.0f);  // Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f, -10.0f);  // Bottom Left Of The Texture and Quad
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -10.0f, -10.0f);  // Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -10.0f);  // Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  10.0f,  10.0f);  // Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  10.0f);  // Bottom Left Of The Texture and Quad
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//BOTTOM PICTURE
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	if(rainbowRoad == true)
	{
	    glBindTexture(GL_TEXTURE_2D, rainbowFloor);
	}
	else if(koopa == true)
	{
	    glBindTexture(GL_TEXTURE_2D, koopaFloor);
	}
	else if(dinosaur == true)
	{
	    glBindTexture(GL_TEXTURE_2D, dinosaurFloor);
	}
	else if(yellowBrick = true)
	{
	    glBindTexture(GL_TEXTURE_2D, yellowBrickFloor);
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D, rainbowFloor);
	}
	glBegin(GL_QUADS);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f, -10.0f, -10.0f);  // Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  10.0f);  // Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  10.0f);  // Bottom Right Of The Texture and Quad
	glDisable(GL_TEXTURE_2D);
	glEnd();
	
	//TOP PICTURE
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	if(rainbowRoad == true)
	{
	    glBindTexture(GL_TEXTURE_2D, rainbowFloor);
	}
	else if(koopa == true)
	{
	    glBindTexture(GL_TEXTURE_2D, koopaFloor);
	}
	else if(dinosaur == true)
	{
	    glBindTexture(GL_TEXTURE_2D, dinosaurFloor);
	}
	else if(yellowBrick = true)
	{
	    glBindTexture(GL_TEXTURE_2D, yellowBrickFloor);
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D, rainbowFloor);
	}
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -10.0f);  // Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  10.0f,  10.0f);  // Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  10.0f,  10.0f);  // Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -10.0f);  // Top Right Of The Texture and Quad
	glDisable(GL_TEXTURE_2D);
	glEnd();

}


void World::idle() {}