/*
=================
- cTileMap.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cTileMap.h"

/*
=================================================================
 Defualt Constructor
=================================================================
*/
cTileMap::cTileMap()
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
cTileMap::cTileMap(vector<cTexture*> tileTextList)
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
cTileMap::cTileMap(vector<cTexture*> tileTextList, int tMap[][8])
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
	tileTextureList = tileTextList;
	initialiseMap(tMap);
}
void cTileMap::render()
{
	mapStartXY = spritePos2D;
	glm::vec2 tilePosXY = mapStartXY;
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			switch (tileMap[row][column])
			{
			case 0:
				GLTextureID = tileTextureList[0]->getTexture();
				break;
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
		tilePosXY.x = mapStartXY.x;
		tilePosXY.y += cSprite::textureHeight;
	}

}

void cTileMap::renderGridLines()
{
	mapStartXY = spritePos2D;
	glm::vec2 tilePosXY = mapStartXY;
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{

			glPushMatrix();

			glTranslatef(tilePosXY.x, tilePosXY.y, 0.0f);

			glBegin(GL_LINE_LOOP);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(0, 0);
			glVertex2f(textureWidth, 0);
			glVertex2f(textureWidth, textureHeight);
			glVertex2f(0, textureHeight);

			glEnd();

			glPopMatrix();

			tilePosXY.x += cSprite::textureWidth;
		}
		tilePosXY.x = mapStartXY.x;
		tilePosXY.y += cSprite::textureHeight;
	}

}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cTileMap::update()
{
	if (m_InputMgr->getLeftMouseBtn() == false)
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (tileToPlace > -1)
		{
			if (areaClicked.x > 100 && areaClicked.x < 612 && areaClicked.y > 100 && areaClicked.y < 612)
			{
				tileClickedRC.x = (int)(areaClicked.x - mapStartXY.x) / textureWidth;
				tileClickedRC.y = (int)(areaClicked.y - mapStartXY.y) / textureHeight;
				tileMap[tileClickedRC.y][tileClickedRC.x] = tileToPlace;
				tileToPlace = -1;
				tileSelected = false;
				m_InputMgr->clearBuffers(m_InputMgr->MOUSE_BUFFER); 
			}
		}
	}

}

/*
=================================================================
- Set the initial values for the map
=================================================================
*/
void cTileMap::initialiseMap(int map[8][8])
{
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			tileMap[row][column] = map[row][column];
		}
	}
	 
}
/*
=================================================================
- Load the texture list with the correct textures
=================================================================
*/
void cTileMap::loadTextures()
{

}
/*
=================================================================
- set start position for tile map
=================================================================
*/
void cTileMap::setMapStartXY(glm::vec2 startPosXY)
{
	mapStartXY = startPosXY;
}
/*
=================================================================
- get start pposition for tile map
=================================================================
*/
glm::vec2 cTileMap::getMapStartXY()
{
	return mapStartXY;
}
/*
=================================================================
- get the tile map as a string
=================================================================
*/
string cTileMap::getMap()
{
	string mapData = "";
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			mapData += to_string(tileMap[row][column]) + ',';
		}
		mapData += '\n';
	}
	return mapData;
}