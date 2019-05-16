#pragma once
#include "SetWindowFullScreen.h"
#include "UIKit.h"

#include "GameObject.h"
//include Menu.h

#include "ManageKeyInput.h"

class GameManager
{
	unsigned short chekForCollision();
	void printWall();
public:
	static GameObject* pGameObject;

	GameManager();


	//Menu menu;


	virtual ~GameManager();
};

