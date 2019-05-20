#pragma once
#include "SetWindowFullScreen.h"
#include "UIKit.h"

#include "GameObject.h"
//include Menu.h

#include "ManageKeyInput.h"

class GameManager
{

	void printWall();
public:
	static GameObject* pGameObject;

	GameManager();


	//Menu menu;

	void chekForCollision();
	virtual ~GameManager();
};

