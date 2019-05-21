#pragma once
#include "SetWindowFullScreen.h"
#include "UIKit.h"

#include "GameObject.h"
#include "Menu.h"
#pragma comment(lib, "winmm.lib")
#include <Mmsystem.h>
#include "ManageKeyInput.h"

class GameManager
{

	void printWall();
public:
	static GameObject* pGameObject;

	GameManager();
	//GameManager(unsigned short inutile);


	//Menu menu;

	void chekForCollision();
	virtual ~GameManager();
};

