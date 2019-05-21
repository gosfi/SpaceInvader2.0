#include "GameManager.h"

GameObject* GameManager::pGameObject = NULL;

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
						if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionY() <= this->pGameObject->pEnnemyTable[j]->coord.getPositionY() + 4
							&& this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionY() >= this->pGameObject->pEnnemyTable[j]->coord.getPositionY())
						{
							if (this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() >= this->pGameObject->pEnnemyTable[j]->coord.getPositionX()
								&& this->pGameObject->pLaserTable.pLaserTable[i]->coord.getPositionX() <= this->pGameObject->pEnnemyTable[j]->coord.getPositionX() + 9)
							{
								PlaySound(TEXT("string\\explosionSound.wav"), NULL, SND_FILENAME || SND_ASYNC);
								this->pGameObject->pEnnemyTable[j]->ajouterPoint();
								UIKit::gotoXY(147, 52);
								UIKit::color(2);
								std::cout << "Points: " << this->pGameObject->pEnnemyTable[j]->getNbPointJoueur();
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

	unsigned short niveau;
	cin >> niveau;
	this->pGameObject = new GameObject(niveau);
	//Menu::activerMenu

	/*string menuItems[4] = { "","","","" };

	Menu m("", menuItems, 4, 10, 15);
	m.afficherMenu();*/



	GameManager::printWall();
	//Boucle de jeu
	bool inGame = true;
	bool hasWin = false;
	char keyInput = 0;
	if (inGame)
	{
		this->pGameObject->pVaisseau.modifierPosition(keyInput);
		while (inGame)
		{
			if (_kbhit())
			{
				keyInput = ManageKeyInput::getKeyInput();
				switch (keyInput)
				{
				case 107:
				case 108:
					this->pGameObject->pVaisseau.modifierPosition(keyInput);
					break;
				case 32:
					this->pGameObject->pLaserTable.creerLaser(this->pGameObject->pVaisseau.coord.getPositionX());
					break;
				}
			}
			if (FrameRate::getFrameRate() % 300 == 0)
			{
				this->pGameObject->pLaserTable.moveLaser();
				this->pGameObject->pEnnemyTable[0]->moveGroupExtraTerrestre(this->pGameObject->pEnnemyTable);
			}
			GameObject::FrameRateManager();
			this->chekForCollision();
			if (this->pGameObject->pEnnemyTable[0]->getNbSaturnienActif() == 0)
			{
				inGame = false;
				hasWin = true;
			}
			else if (this->pGameObject->pEnnemyTable[0]->getPlusGrosY() > 35)
			{
				inGame = false;
				hasWin = false;
			}
		}
	}
	system("cls");
	UIKit::gotoXY(98, 22);
	unsigned short i = 0;
	unsigned short coordX = 88, coordY = 22;
	unsigned short memory1 = coordX;
	switch (hasWin)
	{
	case(true):
	{
		PlaySound(TEXT("string\\winningSound.wav"), NULL, SND_FILENAME || SND_ASYNC);
		UIKit::color(7);
		std::string winScreenGame;
		winScreenGame = GetTextFile::getTxtFile("string\\wingame.txt", 148);
		while (winScreenGame[i] != '\0')
		{
			UIKit::gotoXY(coordX, coordY);
			if (winScreenGame[i] == '\n')
			{
				coordY++;
				coordX = memory1;
			}
			else
			{
				std::cout << winScreenGame[i];
				coordX++;
			}
			i++;
		}
	}
	break;
	case(false):
	{
		PlaySound(TEXT("string\\gameOver.wav"), NULL, SND_FILENAME || SND_ASYNC);
		UIKit::color(7);
		std::string looseScreenGame;
		looseScreenGame = GetTextFile::getTxtFile("string\\gameover.txt", 148);
		while (looseScreenGame[i] != '\0')
		{
			UIKit::gotoXY(coordX, coordY);
			if (looseScreenGame[i] == '\n')
			{
				coordY++;
				coordX = memory1;
			}
			else
			{
				std::cout << looseScreenGame[i];
				coordX++;
			}
			i++;
		}
	}
	break;
	}
	_getch();


}

/*GameManager::GameManager(unsigned short inutile)
{
	GameManager gameManager;
}*/


GameManager::~GameManager()
{
	delete this->pGameObject;
}
