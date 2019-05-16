#pragma once
#include "Coord.h"
class Mur
{
	unsigned short nbElementActif;
	unsigned short nbElementDisponible;
	Coord coordXY[];
public:
	Mur();
	~Mur();
};

