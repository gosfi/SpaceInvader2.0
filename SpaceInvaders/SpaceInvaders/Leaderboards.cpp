#include "Leaderboards.h"
#include <iostream>


Leaderboards::Leaderboards()
{
	char pathToScore[] = ("string\\stringMenu\\Score.txt");
	this->pCheminScore = pathToScore;
	this->scores = GetTextFile::getTxtFile(pCheminScore,101);
}

void Leaderboards::afficherLead()
{
	int touche;
	do 
	{
		system("cls");
		std::cout << scores << std::endl;
		touche = _getch();
	} while (touche!=27);
}


Leaderboards::~Leaderboards()
{
}
