#pragma once
#include "Vaisseau.h"
#include <iostream>
#include "UIKit.h"
#include "GetTextFile.h"
class GrosVaisseau : public Vaisseau{
	char* pCheminVaisseau;
	const unsigned short NB_CHAR_VAISSEAU = 43;
	std::string vaisseau;
	unsigned int coordX, coordY;
	
	void getVaisseauDesign();
	void putVaisseau();
	void removeVaisseau(char key) const;
public:
	GrosVaisseau();
	void modifierPosition(char) override;
};