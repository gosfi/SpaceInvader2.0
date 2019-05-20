#include "GameObject.h"

void GameObject::FrameRateManager()
{
	FrameRate::changeFrame();
}



GameObject::GameObject()
{

	this->pEnnemyTable = new Saturnien*[20];
	int coordX = 50, coordY = 6;
	int memory1 = coordX;

	for (int i = 10; i < 20; i++)
	{
		this->pEnnemyTable[i] = new Saturnien(Ennemie::JOURNALIEN, 100, coordX, coordY);
		coordX += 12;
		if (coordX > 98)
		{
			coordY += 5;
			coordX = memory1;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		this->pEnnemyTable[i] = new Saturnien(Ennemie::SATURNIEN, 50, coordX, coordY);
		coordX += 12;
		if (coordX > 98)
		{
			coordY += 5;
			coordX = memory1;
		}
	}	

}



GameObject::~GameObject()
{
	for (int i = 0; i < 20; i++)
	{
		if (this->pEnnemyTable[i] != NULL)
		{
			delete this->pEnnemyTable[i];
		}
	}
	delete[] this->pEnnemyTable;
}