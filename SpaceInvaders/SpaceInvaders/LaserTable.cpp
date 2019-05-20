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

void LaserTable::startLaser(int x)
{
	this->coord.setPositionX(x);
	this->coord.setPositionY(44);
	this->putLaser();
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

void LaserTable::removeLaser(unsigned short indice)
{
	this->pLaserTable[indice]->killLaser();
	delete pLaserTable[indice];
	this->pLaserTable[indice] = NULL;
	this->nbLaserActif--;
}

void LaserTable::moveLaser()
{
	UIKit::color(13);
	for (int i = 0; i < this->nbLaserDisponible; i++)
	{
		if (this->pLaserTable[i] != NULL)
		{
			//TODO chek colision si il y a colision, remove le laser
			if (this->pLaserTable[i]->coord.getPositionY() == 2)
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

unsigned short LaserTable::getNbLaserActif()
{
	return this->nbLaserActif;
}

unsigned short LaserTable::getNbLaserDisponible()
{
	return this->nbLaserDisponible;
}

LaserTable::~LaserTable()
{
	for (int i = 0; i < this->nbLaserDisponible; i++)
	{
		delete this->pLaserTable[i];
	}
	delete[] this->pLaserTable;
}
