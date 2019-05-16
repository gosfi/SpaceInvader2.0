#include "GameManager.h"
#include <conio.h>
using namespace std;

int main()
{
	GameManager gameManager;
	bool inGame = true;
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

		GameObject::FrameRateManager();
		Sleep(60);
	}
	_getch();
	return 0;
}