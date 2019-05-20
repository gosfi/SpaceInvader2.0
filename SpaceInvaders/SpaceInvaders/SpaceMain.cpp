#include "GameManager.h"
#include <conio.h>
using namespace std;
#include "Saturnien.h"
int main()
{
	GameManager gameManager;
	bool inGame = true;
	short collision = 999;
	char keyInput = 0;

	gameManager.pGameObject->pVaisseau.modifierPosition(keyInput);
	while (inGame)
	{
		if (_kbhit())
		{
			keyInput = ManageKeyInput::getKeyInput();
			switch (keyInput)
			{
			case 107:
			case 108:
				gameManager.pGameObject->pVaisseau.modifierPosition(keyInput);
				break;
			case 32:
				gameManager.pGameObject->pLaserTable.creerLaser(gameManager.pGameObject->pVaisseau.coord.getPositionX());
				break;
			}
		}
		gameManager.pGameObject->pLaserTable.moveLaser();
		if (FrameRate::getFrameRate() % 6 == 0)
		{
			gameManager.pGameObject->pEnnemyTable[0]->moveGroupExtraTerrestre(gameManager.pGameObject->pEnnemyTable);
		}
		GameObject::FrameRateManager();
		gameManager.chekForCollision();
		Sleep(60);
	}
	_getch();
	return 0;
}