#pragma once
#include "Laser.h"
#include "Tableau.h"
class LaserTable : public Laser {
	Laser** pLaserTable;
	unsigned short nbLaserActif;
	unsigned short nbLaserDisponible;

public:
	LaserTable();
	void creerLaser(int coordXVaisseau);
	void moveLaser();

	~LaserTable();
};