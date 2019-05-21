#include "MenuOptions.h"
#include <iostream>


MenuOptions::MenuOptions()
{
}

void MenuOptions::afficherOptions()
{
	int touche;

	do
	{
		system("cls");
		std::cout << "En construction" << endl;
		std::cout << "Appuyez sur (1) pour utiliser les lettres et (2) pour utiliser les fleches" << endl;
		std::cout << "Appuyez sur escape pour revenir en arriere";
		touche = _getch();

	} while (touche != 27);



}


MenuOptions::~MenuOptions()
{
}
