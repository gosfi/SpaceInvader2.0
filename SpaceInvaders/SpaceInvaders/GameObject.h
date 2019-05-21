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
	unsigned short nbEnnemie;

public:
	GameObject();
	GameObject(unsigned short niveau);
	static void FrameRateManager();
	LaserTable pLaserTable;

	GrosVaisseau pVaisseau;

	Saturnien** pEnnemyTable;
	Mur tableMur[6];

	~GameObject();
};