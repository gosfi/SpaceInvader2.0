#include "GameObject.h"

void GameObject::FrameRateManager()
{
	FrameRate::changeFrame();
}



GameObject::GameObject()
{
}

GameObject::GameObject(unsigned short niveau)
{
	this->pEnnemyTable = new Saturnien*[20];
	int coordX = 50, coordY = 6;
	int memory1 = coordX;
	switch (niveau)
	{
	case(1):
		this->nbEnnemie = 10;
		for (int i = 0; i < 10; i++)
		{
			this->pEnnemyTable[i] = new Saturnien(Ennemie::SATURNIEN, 50, coordX, coordY, niveau);
			coordX += 12;
			if (coordX > 98)
			{
				coordY += 5;
				coordX = memory1;
			}
		}
		break;
	case(2):
		this->nbEnnemie = 15;
		for (int i = 10; i < 15; i++)
		{
			this->pEnnemyTable[i] = new Saturnien(Ennemie::JOURNALIEN, 100, coordX, coordY, niveau);
			coordX += 12;
			if (coordX > 98)
			{
				coordY += 5;
				coordX = memory1;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			this->pEnnemyTable[i] = new Saturnien(Ennemie::SATURNIEN, 50, coordX, coordY, niveau);
			coordX += 12;
			if (coordX > 98)
			{
				coordY += 5;
				coordX = memory1;
			}
		}
		break;
	case(3):
		this->nbEnnemie = 20;
		for (int i = 10; i < 20; i++)
		{
			this->pEnnemyTable[i] = new Saturnien(Ennemie::JOURNALIEN, 100, coordX, coordY, niveau);
			coordX += 12;
			if (coordX > 98)
			{
				coordY += 5;
				coordX = memory1;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			this->pEnnemyTable[i] = new Saturnien(Ennemie::SATURNIEN, 50, coordX, coordY, niveau);
			coordX += 12;
			if (coordX > 98)
			{
				coordY += 5;
				coordX = memory1;
			}
		}
		break;
	}	

}



GameObject::~GameObject()
{
	for (int i = 0; i < this->nbEnnemie; i++)
	{
		if (this->pEnnemyTable[i] != NULL)
		{
			delete this->pEnnemyTable[i];
		}
	}
	delete[] this->pEnnemyTable;
}