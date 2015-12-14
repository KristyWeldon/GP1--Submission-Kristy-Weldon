/*
=================
- cButton.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cButton.h"

/*
=================================================================
 Defualt Constructor
=================================================================
*/
cButton::cButton()
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
}

void cButton::render()
{
	setSpriteCentre();

	glPushMatrix();

	glTranslatef(spritePos2D.x, spritePos2D.y, 0.0f);

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

}

void cButton::render(int textureToRender)
{
	GLTextureID = textureToRender;
	setSpriteCentre();

	glPushMatrix();

	glTranslatef(spritePos2D.x, spritePos2D.y, 0.0f);

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

}

/*
=================================================================
Update the sprite position
=================================================================
*/

void cButton::update()
{

	if (m_InputMgr->getLeftMouseBtn())
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (areaClicked.x >= spritePos2D.x && areaClicked.x <= (spritePos2D.x + textureWidth) && areaClicked.y >= spritePos2D.y && areaClicked.y <= (spritePos2D.y + textureHeight))
		{
			buttonClickedRC.x = (int)(areaClicked.x - spritePos2D.x) / textureWidth;
			buttonClickedRC.y = (int)(areaClicked.y - spritePos2D.y) / textureHeight;
			clicked = true;
			m_InputMgr->clearBuffers(m_InputMgr->MOUSE_BUFFER);// clear mouse buffer.
		}
	}
}

void cButton::update(string fileName, string map)
{

	if (m_InputMgr->getLeftMouseBtn())
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (areaClicked.x >= spritePos2D.x && areaClicked.x <= (spritePos2D.x + textureWidth) && areaClicked.y >= spritePos2D.y && areaClicked.y <= (spritePos2D.y + textureHeight))
		{
			buttonClickedRC.x = (int)(areaClicked.x - spritePos2D.x) / textureWidth;
			buttonClickedRC.y = (int)(areaClicked.y - spritePos2D.y) / textureHeight;
			clicked = true;
			
			cFileHandler aFile(fileName);

			if (!aFile.openFile(ios::out)) //open file clearing the contents
			{
				MessageBox(NULL, "Could not open specified file.", "An error occurred", MB_ICONERROR | MB_OK);
			}
			else
			{
				// Read data from map and write to file
				string mapData = "";
				int strPos = 0;
				for (int row = 0; row < 8; row++)
				{
					for (int column = 0; column < 15; column++)
					{
						mapData += map[strPos];
						strPos++;
					}
					strPos++;
					mapData += map[strPos];
					aFile.writeDataToFile(mapData);
					mapData = "";
					strPos++;
				}
				aFile.closeFile();
			}
			m_InputMgr->clearBuffers(m_InputMgr->MOUSE_BUFFER);// clear mouse buffer.
		}
	}
}

gameState cButton::update(gameState theCurrentGameState, gameState newGameState)
{

	if (m_InputMgr->getLeftMouseBtn())
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (areaClicked.x >= spritePos2D.x && areaClicked.x <= (spritePos2D.x + textureWidth) && areaClicked.y >= spritePos2D.y && areaClicked.y <= (spritePos2D.y + textureHeight))
		{
			buttonClickedRC.x = (int)(areaClicked.x - spritePos2D.x) / textureWidth;
			buttonClickedRC.y = (int)(areaClicked.y - spritePos2D.y) / textureHeight;
			clicked = true;
			m_InputMgr->clearBuffers(m_InputMgr->MOUSE_BUFFER);// clear mouse buffer.
			return newGameState;
		}
	}
	return theCurrentGameState;
}

bool cButton::getClicked()
{
	return clicked;
}
void cButton::setClicked(bool state)
{
	clicked = state;
}
