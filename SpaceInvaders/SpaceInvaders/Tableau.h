#pragma once
#include "Laser.h"
class Tableau {

public:
	static void grossirLaserTable(Laser** &pTableLaser, unsigned short& grosseurDisponible);
	static void rapetisserLaserTable(Laser** &pTableLaser, unsigned short& grosseurDisponible);
	static void putEmptySpaceToTheEnd(Laser** &pTableLaser, const unsigned short &nbUtiliser, const unsigned short& grosseurDisponible);
};