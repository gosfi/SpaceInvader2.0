#include "GameManager.h"

GameObject* GameManager::pGameObject = new GameObject;

void GameManager::chekForCollision()
{
	//Boucle pour le nombre de laser disponible
	for (int i = 0; i < this->pGameObject->pLaserTable.getNbLaserDisponible(); i++)
	{
		if (this->pGameObject->pLaserTable.pLaserTable[i] != NULL)
		{
			if (UIKit::getCharXY(this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX(), this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() - 1) != NULL
			|| UIKit::getCharXY(this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX(), this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() - 1) != char(32))
			{
				if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionY() > 40)
				{
#pragma region collisionMur
					//Boucle pour le nombre de mur
					for (int j = 0; j < 6; j++)
					{
						//Boucle pour le nombre de caracter par mur (22)
						for (int k = 0; k < 26; k++)
						{
							if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionY() == this->pGameObject->tableMur[j].coords[k].getPositionY()
								&& this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() == this->pGameObject->tableMur[j].coords[k].getPositionX())
							{
								UIKit::gotoXY(this->pGameObject->tableMur[j].coords[k].getPositionX(), this->pGameObject->tableMur[j].coords[k].getPositionY());
								std::cout << char(32);
								this->pGameObject->tableMur[j].coords[k].setPositionX(0);
								this->pGameObject->tableMur[j].coords[k].setPositionY(0);
								this->pGameObject->pLaserTable.removeLaser(i);
								j = 6;
								k = 26;

							}
						}

					}
#pragma endregion collisionMur
				}
				else
				{
#pragma region collisionEnnemi
					for (int j = 0; j < this->pGameObject->pEnnemyTable[0]->getNbSaturnienActif(); j++)
					{
							if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionY() <= this->pGameObject->pEnnemyTable[j]->coord.getPositionY() + 4)
							{
								if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() >= this->pGameObject->pEnnemyTable[j]->coord.getPositionX() 
									&& this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() <= this->pGameObject->pEnnemyTable[j]->coord.getPositionX() + 9)
								{
									this->pGameObject->pEnnemyTable[j]->ajouterPoint();
									UIKit::gotoXY(200, 1);
									UIKit::color(7);
									std::cout << "Point: " << this->pGameObject->pEnnemyTable[j]->getNbPointJoueur();
									this->pGameObject->pEnnemyTable[j]->removeExtraTerrestre();
									this->pGameObject->pEnnemyTable[j]->killEnnemie(this->pGameObject->pEnnemyTable, j);
									this->pGameObject->pLaserTable.removeLaser(i);
									j = this->pGameObject->pEnnemyTable[0]->getNbSaturnienActif();
								}
							}

					}
#pragma endregion collisionEnnemi
				}
			}
		}
	}
}

void GameManager::printWall()
{
	std::string wallDesign = GetTextFile::getTxtFile("string\\mur.txt", 31);

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
				if (wallDesign[o] != 32)
				{
					this->pGameObject->tableMur[i].setCoordyXY(o, coordX, coordY);
				}
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
	SetWindowFullScreen::setFullScreen();
	UIKit::curseurVisible(false);
	UIKit::cadre(40, 1, 161, 53, 15);

	//Menu::activerMenu



	GameManager::printWall();
	//Boucle de jeu


}


GameManager::~GameManager()
{
	delete this->pGameObject;
}
