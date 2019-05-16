#include "GameManager.h"

GameObject* GameManager::pGameObject = new GameObject;

unsigned short GameManager::chekForCollision()
{
	return 0;
}

void GameManager::printWall()
{
	std::string wallDesign = GetTextFile::getTxtFile("C:\\Users\\gdesgagn\\source\\repos\\SpaceInvader-Project\\SpaceInvader-Project\\string\\mur.txt", 31);

	unsigned int coordX = 47;
	for (int i = 0; i < 6; i++)
	{
		unsigned int coordY = 40;
		unsigned short o = 0;
		unsigned memory1 = coordX;
		while (wallDesign[o] != '\0')
		{
			UIKit::gotoXY(coordX, coordY);
			if (wallDesign[o] == '\n')
			{
				coordY++;
				coordX = memory1;
			}
			else 
			{
				pGameObject->mur[i]
				std::cout << wallDesign[o];
				coordX++;
			}
			o++;
		}
		coordX += 20;
	}
}

GameManager::GameManager()
{
	SetWindowFullScreen lol;
	lol.setFullScreen();
	//Menu::activerMenu
	UIKit::cadre(40, 1, 161, 53, 15);
	GameManager::printWall();
	UIKit::curseurVisible(false);	
	//Boucle de jeu
	

}


GameManager::~GameManager()
{
	delete this->pGameObject;
}
