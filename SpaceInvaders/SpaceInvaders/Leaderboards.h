#pragma once
#include <string>
#include "GetTextFile.h"
#include <conio.h>
class Leaderboards
{
	char*pCheminScore;
	std::string scores;
public:
	Leaderboards();
	void afficherLead();
	~Leaderboards();
};

