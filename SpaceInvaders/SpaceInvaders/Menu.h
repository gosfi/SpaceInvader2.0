//la classe menu

#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include "GetTextFile.h"
#include "UIKit.h"
#include "SetWindowFullScreen.h"
#include "MenuOptions.h"
#include "Leaderboards.h"
using namespace std;
#include <string>
#include <windows.h>	//pour Sleep et gotoXY et COORD
#include <conio.h>	//pour getch
#include <ctype.h>	//pour tolower

//la classe Menu pour gérer les flèches
class Menu
{
	
protected:
	
	char*pCheminTitre;
	char*pCheminPlay;
	char*pCheminOptions;
	char*pcheminLeaderboards;
	char*pCheminQuit;
	string _titre;
	int _nbItem;
	string* _listeChoix;
	COORD coinHG;
	//gestion interne
	COORD _posActu;
	COORD _posLast;
	COORD _posFirst;
	int choix;

protected:
	void deplacer(COORD origine, COORD cible);
	int getTailleMax();
	void gotoXY(COORD pos);
	void init();


public:
	Menu(string titre, string* listeChoix, int nbItem, int ligneDebut, int coloneDebut);
	Menu();
	~Menu();
	int afficherMenu();
	void gotoXY(int c, int l);
};

#endif