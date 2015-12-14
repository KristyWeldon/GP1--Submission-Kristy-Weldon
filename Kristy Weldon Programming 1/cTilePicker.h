/*
=================
cTilePicker.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CTILEPICKER_H
#define _CTILEPICKER_H
#include "cSprite.h"
#include "mazeMaker.h"

class cTilePicker : public cSprite
{
protected:
	int tilePickingList[4][3];
	int tileMap[8][8];

private:
	vector<cTexture*> tileTextureList;
	glm::vec2 tileListStartXY;
	glm::ivec2 tileClickedRC;

	void initialiseTileList();		// Set the initial values for the map
	void loadTextures();		// Load the texture list with the correct textures

public:
	cTilePicker();
	cTilePicker(vector<cTexture*> tileTextList);
	cTilePicker(vector<cTexture*> tileTextList, int tMap[][8]);

	void render();		// Default render function
	void update();
	void setTileListStartXY(glm::vec2 startPosXY);
	glm::vec2 getTileListStartXY();
};
#endif