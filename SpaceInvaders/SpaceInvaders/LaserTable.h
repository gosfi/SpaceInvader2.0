#pragma once
#include "Laser.h"
#include "Tableau.h"
class LaserTable : public Laser {
	unsigned short nbLaserActif;
	unsigned short nbLaserDisponible;

public:
	Laser** pLaserTable;
	LaserTable();
	void startLaser(int) override;
	void creerLaser(int coordXVaisseau);
	void removeLaser(unsigned short indice);
	void moveLaser();

	unsigned short getNbLaserActif();
	unsigned short getNbLaserDisponible();

	~LaserTable();
};