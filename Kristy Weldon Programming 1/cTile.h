/*
=================
cTile.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CTILE_H
#define _CTILE_H
#include "cSprite.h"
#include "mazeMaker.h"


class cTile: public cSprite
{

private:

	glm::ivec2 tileClickedRC;

public:
	cTile();

	void setTextureWidth();


	void render();		// Default render function
	void render(int textureToRender);		// Default render function
	void update();
};
#endif