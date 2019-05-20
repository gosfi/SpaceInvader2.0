#pragma once
#include "Coord.h"
class Mur
{
public:
	Coord coords[26];

	Mur();

	void setCoordyXY(unsigned short indice, int coordX, int coordY);

	~Mur();
};

