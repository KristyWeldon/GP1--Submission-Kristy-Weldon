/*
=================
- cTilePicker.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cTilePicker.h"

/*
=================================================================
 Defualt Constructor
=================================================================
*/
cTilePicker::cTilePicker()
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
}

/*
=================================================================
Defualt Constructor
=================================================================
*/
cTilePicker::cTilePicker(vector<cTexture*> tileTextList)
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
	tileTextureList = tileTextList;
}
/*
=================================================================
Defualt Constructor
=================================================================
*/
cTilePicker::cTilePicker(vector<cTexture*> tileTextList, int tMap[][8])
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
	tileTextureList = tileTextList;
	initialiseTileList();
}
void cTilePicker::render()
{
	tileListStartXY = spritePos2D;
	glm::vec2 tilePosXY = tileListStartXY;
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			switch (tilePickingList[row][column])
			{
				case 1:
					GLTextureID = tileTextureList[1]->getTexture();
					break;
				case 2:
					GLTextureID = tileTextureList[2]->getTexture();
					break;
				case 3:
					GLTextureID = tileTextureList[3]->getTexture();
					break;
				case 4:
					GLTextureID = tileTextureList[4]->getTexture();
					break;
				case 5:
					GLTextureID = tileTextureList[5]->getTexture();
					break;
				case 6:
					GLTextureID = tileTextureList[6]->getTexture();
					break;
			}
			
			setTextureDimensions(tileTextureList[0]->getTWidth(), tileTextureList[0]->getTHeight());
			setSpriteCentre();

			glPushMatrix();

			glTranslatef(tilePosXY.x, tilePosXY.y, 0.0f);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

			glBegin(GL_QUADS);
			glColor3f(255.0f, 255.0f, 255.0f);
			glTexCoord2f(spriteTexCoordData[0].x, spriteTexCoordData[0].y);
			glVertex2f(0, 0);
			glTexCoord2f(spriteTexCoordData[1].x, spriteTexCoordData[1].y);
			glVertex2f(textureWidth, 0);
			glTexCoord2f(spriteTexCoordData[2].x, spriteTexCoordData[2].y);
			glVertex2f(textureWidth, textureHeight);
			glTexCoord2f(spriteTexCoordData[3].x, spriteTexCoordData[3].y);
			glVertex2f(0, textureHeight);

			glEnd();
			glDisable(GL_TEXTURE_2D);

			glPopMatrix();

			tilePosXY.x += cSprite::textureWidth;
		}
		tilePosXY.x = tileListStartXY.x;
		tilePosXY.y += cSprite::textureHeight;
	}
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cTilePicker::update()
{
	if (m_InputMgr->getLeftMouseBtn() && !tileSelected)
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (areaClicked.x > 740 && areaClicked.x < 932 && areaClicked.y > 100 && areaClicked.y < 228)
		{
			tileClickedRC.x = (int)(areaClicked.x - tileListStartXY.x) / textureWidth;
			tileClickedRC.y = (int)(areaClicked.y - tileListStartXY.y) / textureHeight;
			tileToPlace = tilePickingList[tileClickedRC.y][tileClickedRC.x];
			tileSelected = true;
		}
	}

}

/*
=================================================================
- Set the initial values for the map
=================================================================
*/
void cTilePicker::initialiseTileList()
{
	int tile = 1;
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			tilePickingList[row][column] = tile;
			tile++;
		}
	}
	 
}
/*
=================================================================
- Load the texture list with the correct textures
=================================================================
*/
void cTilePicker::loadTextures()
{

}
/*
=================================================================
- set start position for tile map
=================================================================
*/
void cTilePicker::setTileListStartXY(glm::vec2 startPosXY)
{
	tileListStartXY = startPosXY;
}
/*
=================================================================
- get start pposition for tile map
=================================================================
*/
glm::vec2 cTilePicker::getTileListStartXY()
{
	return tileListStartXY;
}
