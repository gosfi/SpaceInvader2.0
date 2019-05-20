#include "Journalien.h"

unsigned int Journalien::nbPointJoueur;
unsigned short Journalien::nbSaturnienActif = 10;
int Journalien::plusGrosX = 0;
int Journalien::plusPetitX = 0;

Journalien::Journalien(int type, int valeur, unsigned int coordX, unsigned int coordY) : ExtraTerrestre(type, valeur)
{
	this->typeExtraTerrestre = type;
	this->moveDirection = 'R';
	char folderPathExtraterrestre[] = "string\\extraTerrestre.txt";
	this->pCheminExtraTerrestre = folderPathExtraterrestre;
	this->saturnien = GetTextFile::getTxtFile(pCheminExtraTerrestre, NB_CHAR_SATURNIEN);
	int i = 0;
	while (this->saturnien[i] != '\0')
	{
		if (this->saturnien[i] == 'S')
		{
			this->saturnien[i] = char(223);
		}
		else if (this->saturnien[i] == 'A')
		{
			this->saturnien[i] = char(220);
		}
		else if (this->saturnien[i] == 'F')
		{
			this->saturnien[i] = char(219);
		}
		else if (this->saturnien[i] == 'D')
		{
			this->saturnien[i] = char(220);
		}


		i++;
	}
	this->setCoordExtraterrestre(coordX, coordY);
}

void Journalien::moveGroupExtraTerrestre(Journalien ** &pTableExtraTerrestre)
{
	//Remove tt les exraTerrestre de l ecran
	for (int i = 0; i < this->nbSaturnienActif; i++)
	{
		pTableExtraTerrestre[i]->removeExtraTerrestre();
	}

	//Trouver plus gros X et plus petit X
	for (int i = 0; i < this->nbSaturnienActif; i++)
	{
		if (i == 0)
		{
			this->plusGrosX = pTableExtraTerrestre[i]->coord.getPositionX() + 9;
			this->plusPetitX = pTableExtraTerrestre[i]->coord.getPositionX();
		}
		else
		{
			if (pTableExtraTerrestre[i]->coord.getPositionX() < this->plusPetitX)
			{
				this->plusPetitX = pTableExtraTerrestre[i]->coord.getPositionX();
			}
			else if (pTableExtraTerrestre[i]->coord.getPositionX() > this->plusGrosX)
			{
				this->plusGrosX = pTableExtraTerrestre[i]->coord.getPositionX();
			}
		}
	}

	//Chek si il faut move down
	if (this->plusPetitX == 41 && this->moveDirection == 'L')
	{
		this->moveDirection = 'D';
		for (int i = 0; i < this->nbSaturnienActif; i++)
		{
			pTableExtraTerrestre[i]->moveExtraTerrestre(this->moveDirection);
		}
		this->moveDirection = 'R';
	}
	else if (this->plusGrosX == 152 && this->moveDirection == 'R')
	{
		this->moveDirection = 'D';
		for (int i = 0; i < this->nbSaturnienActif; i++)
		{
			pTableExtraTerrestre[i]->moveExtraTerrestre(this->moveDirection);
		}
		this->moveDirection = 'L';
	}
	else
	{
		for (int i = 0; i < this->nbSaturnienActif; i++)
		{
			pTableExtraTerrestre[i]->moveExtraTerrestre(this->moveDirection);
		}
	}

	for (int i = 0; i < this->nbSaturnienActif; i++)
	{
		pTableExtraTerrestre[i]->putExtraTerrestre();
	}
}

void Journalien::killEnnemie(Journalien ** &pTableExtraTerrestre, unsigned int indice)
{
	if (indice != this->nbSaturnienActif - 1)
	{
		delete pTableExtraTerrestre[indice];
		pTableExtraTerrestre[indice] = pTableExtraTerrestre[this->nbSaturnienActif - 1];
	}
	else
	{
		delete pTableExtraTerrestre[this->nbSaturnienActif - 1];
	}
	pTableExtraTerrestre[this->nbSaturnienActif - 1] = NULL;
	this->nbSaturnienActif--;
}

unsigned short Journalien::getNbSaturnienActif()
{
	return this->nbSaturnienActif;
}

unsigned short Journalien::getNbPointJoueur()
{
	return this->nbPointJoueur;
}

unsigned short Journalien::getTypeExtraTerrestre() const
{
	return this->typeExtraTerrestre;
}

void Journalien::ajouterPoint()
{
	switch (getTypeExtraTerrestre())
	{
	case(1):
		this->nbPointJoueur += 50;
		break;
	case(2):
		this->nbPointJoueur += 100;
		break;
	case(3):
		this->nbPointJoueur += 200;
		break;
	}
}



void Journalien::setCoordExtraterrestre(int coordX, int coordY)
{
	this->coord.setPositionX(coordX);
	this->coord.setPositionY(coordY);
}

void Journalien::moveExtraTerrestre(char moveDirection)
{
	switch (moveDirection)
	{
	case('R'):
		this->coord.setPositionX(this->coord.getPositionX() + 1);
		break;
	case('L'):
		this->coord.setPositionX(this->coord.getPositionX() - 1);
		break;
	case('D'):
		this->coord.setPositionY(this->coord.getPositionY() + 2);
		break;
	}
}

void Journalien::putExtraTerrestre()
{
	UIKit::color(2);
	unsigned short i = 0;
	this->coordX = this->coord.getPositionX();
	this->coordY = this->coord.getPositionY();
	unsigned int memory1 = coordX;

	while (this->saturnien[i] != '\0')
	{
		UIKit::gotoXY(coordX, coordY);
		if (this->saturnien[i] == '\n')
		{
			coordY++;
			coordX = memory1;
		}
		else
		{
			std::cout << this->saturnien[i];
			coordX++;
		}
		i++;
	}
}

void Journalien::removeExtraTerrestre()
{
	unsigned short i = 0;
	this->coordX = this->coord.getPositionX();
	this->coordY = this->coord.getPositionY();
	unsigned int memory1 = coordX;

	for (int i = 0; i < 4; i++)
	{
		UIKit::gotoXY(coordX, coordY);
		cout << "         ";
		coordY++;
		coordX = memory1;
	}
}


Journalien::~Journalien()
{
}
