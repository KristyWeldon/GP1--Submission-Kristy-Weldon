/*
=================
cButton.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CBUTTON_H
#define _CBUTTON_H
#include "cSprite.h"
#include "mazeMaker.h"
#include "cFileHandler.h"


class cButton : public cSprite
{

private:

	glm::ivec2 buttonClickedRC;
	bool clicked = false; 

public:
	cButton();

	void setTextureWidth();


	void render();		// Default render function
	void render(int textureToRender);		// Default render function
	void update();
	void update(string fileName, string map);
	gameState update(gameState theCurrentGameState, gameState newGameState);

	bool getClicked();
	void setClicked(bool state);

};
#endif