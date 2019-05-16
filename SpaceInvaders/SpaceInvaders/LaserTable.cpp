#include "LaserTable.h"
#include "UIKit.h"
#include <iostream>
#include "FrameRate.h"

LaserTable::LaserTable()
{
	this->pLaserTable = new Laser*[2];
	this->pLaserTable[0] = NULL;
	this->pLaserTable[1] = NULL;
	this->nbLaserActif = 0;
	this->nbLaserDisponible = 2;
}

void LaserTable::creerLaser(int coordXVaisseau)
{
	if (FrameRate::getColdDownForLaser() == 0)
	{
		UIKit::color(RGB(0, 255, 0));
		this->nbLaserActif++;
		if (nbLaserActif > nbLaserDisponible)
		{
			Tableau::grossirLaserTable(pLaserTable, this->nbLaserDisponible);
		}
		int indice = 0;
		while (this->pLaserTable[indice] != NULL)
		{
			indice++;
		}
		this->pLaserTable[indice] = new Laser;
		this->pLaserTable[indice]->startLaser(coordXVaisseau + 4);
		if (nbLaserActif == (nbLaserDisponible / 2) - 1)
		{
			Tableau::putEmptySpaceToTheEnd(pLaserTable, this->nbLaserActif, this->nbLaserDisponible);
			Tableau::rapetisserLaserTable(pLaserTable, this->nbLaserDisponible);
		}
		FrameRate::setColdDownForLaser();
	}
}

void LaserTable::moveLaser()
{
	UIKit::color(13);
	for (int i = 0; i < this->nbLaserDisponible; i++)
	{
		if (this->pLaserTable[i] != NULL)
		{
			//TODO chek colision si il y a colision, remove le laser
			if (this->pLaserTable[i]->coord.getPositionY() == 10)
			{
				this->pLaserTable[i]->killLaser();
				delete pLaserTable[i];
				this->pLaserTable[i] = NULL;
				this->nbLaserActif--;
			}
			else
			{
				this->pLaserTable[i]->moveLaser();
			}
		}
	}
}

LaserTable::~LaserTable()
{
	for (int i = 0; i < this->nbLaserDisponible; i++)
	{
		delete this->pLaserTable[i];
	}
	delete[] this->pLaserTable;
}
