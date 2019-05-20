#include "Mur.h"

Mur::Mur()
{
}

void Mur::setCoordyXY(unsigned short indice, int coordX, int coordY)
{
	this->coords[indice].setPositionX(coordX);
	this->coords[indice].setPositionY(coordY);
}


Mur::~Mur()
{

}
