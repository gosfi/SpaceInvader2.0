#pragma once
#include "ExtraTerrestre.h"
#include <string>
#include "UIKit.h"
#include "GetTextFile.h"
class Saturnien : public ExtraTerrestre
{
	static unsigned int nbPointJoueur;
	static unsigned short nbSaturnienActif;
	static int plusGrosX, plusPetitX;

	char moveDirection;
	char* pCheminExtraTerrestre;
	const unsigned short NB_CHAR_SATURNIEN = 132;
	std::string saturnien;

	unsigned int coordX, coordY;
	unsigned short typeExtraTerrestre;

	void setCoordExtraterrestre(int coordX, int coordY);

	void moveExtraTerrestre(char moveDirection);
	void putExtraTerrestre();

	unsigned short getTypeExtraTerrestre() const;

public:
	Saturnien(int type, int valeur, unsigned int coordX, unsigned int coordY);

	void moveGroupExtraTerrestre(Saturnien** &pTableExtraTerrestre);
	void killEnnemie(Saturnien ** &pTableExtraTerrestre, unsigned int indice);
	void removeExtraTerrestre();

	void ajouterPoint();
	unsigned short getNbSaturnienActif();
	unsigned short getNbPointJoueur();

	~Saturnien();
};

