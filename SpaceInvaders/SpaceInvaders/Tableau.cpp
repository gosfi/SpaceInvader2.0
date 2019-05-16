#include "Tableau.h"
#include "Laser.h"
#include <iostream>

void Tableau::grossirLaserTable(Laser** &pTableLaser, unsigned short& grosseurDisponible)
{
	//Creer table plus 2x plus grosse
	Laser** pTemp = new Laser*[grosseurDisponible * 2];

	//Mettre données ancien tableau dans nouveau
	for (int i = 0; i < grosseurDisponible; i++)
	{
		pTemp[i] = pTableLaser[i];
	}
	//Delete ancien pointeur de l'ancien tableau
	delete[] pTableLaser;

	//Mettre les case inutiliser a NULL;
	for (int i = grosseurDisponible; i < grosseurDisponible * 2; i++)
	{
		pTemp[i] = NULL;
	}
	grosseurDisponible *= 2;
	pTableLaser = pTemp;
	pTemp = NULL;
}

void Tableau::rapetisserLaserTable(Laser** &pTableLaser, unsigned short& grosseurDisponible)
{
	//Creer une table 2x plus petite
	grosseurDisponible /= 2;
	Laser** pTemp = new Laser*[grosseurDisponible];

	//Echanger les valeur de l'ancienne table vers la nouevelle
	for (int i = 0; i < grosseurDisponible - 1; i++)
	{
		pTemp[i] = pTableLaser[i];
	}

	//Delete l'ancien tableau
	delete[] pTableLaser;

	//Setter la case inutiliser a NULL;
	pTemp[grosseurDisponible - 1] = NULL;

	pTableLaser = pTemp;
	pTemp = NULL;
}

void Tableau::putEmptySpaceToTheEnd(Laser** &pTableLaser,const unsigned short &nbUtiliser,const unsigned short &grosseurDisponible)
{
	int o = grosseurDisponible - 1;
	for (int i = 0; i < nbUtiliser; i++)
	{
		if (pTableLaser[i] == NULL)
		{
			while (pTableLaser[o] == NULL)
			{
				o--;
			}
			pTableLaser[i] = pTableLaser[o];
			pTableLaser[o] = NULL;
		}
	}
}

