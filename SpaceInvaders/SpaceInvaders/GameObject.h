#pragma once
#include "FrameRate.h"
#include "GetTextFile.h"

#include "GrosVaisseau.h"
#include "LaserTable.h"

#include "ExtraTerrestre.h"
#include "Martien.h"

#include "Mur.h"
class GameObject {
	//void LaserManager();

public:

	GameObject();
	static void FrameRateManager();
	LaserTable pLaserTable;
	Ennemi pEnnmiTable;

	GrosVaisseau pVaisseau;

	Mur tableMur[6];
	//pEnnemyTable

	
};