#pragma once
#include "FrameRate.h"
#include "GetTextFile.h"

#include "GrosVaisseau.h"
#include "LaserTable.h"

#include "Saturnien.h"
#include "ExtraTerrestre.h"
#include "Martien.h"

#include "Mur.h"


enum Ennemie {
	SATURNIEN = 1,
	JOURNALIEN
};
class GameObject {
	//void LaserManager();

public:

	GameObject();
	static void FrameRateManager();
	LaserTable pLaserTable;
	//Ennemi pEnnmiTable;

	GrosVaisseau pVaisseau;

	Saturnien** pEnnemyTable;
	Mur tableMur[6];

	//pEnnemyTable

	~GameObject();
};