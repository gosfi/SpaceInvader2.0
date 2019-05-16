#include "GrosVaisseau.h"

void GrosVaisseau::getVaisseauDesign()
{
	this->vaisseau = GetTextFile::getTxtFile(pCheminVaisseau, NB_CHAR_VAISSEAU);
}

GrosVaisseau::GrosVaisseau()
{
	char folderPathToVaisseau[]("C:\\Users\\gdesgagn\\source\\repos\\SpaceInvader-Project\\SpaceInvader-Project\\string\\vaisseau.txt");
	this->pCheminVaisseau = folderPathToVaisseau;
	this->getVaisseauDesign();
}

void GrosVaisseau::modifierPosition(char key)
{
	switch (key)
	{
	case 'k':
		coord.setPositionX(coord.getPositionX() - 1);
		if (this->coord.getPositionX() <= 40)
		{
			this->coord.setPositionX(this->coord.getPositionX() + 1);
		}
		break;
	case 'l':
		coord.setPositionX(coord.getPositionX() + 1);
		if (this->coord.getPositionX() >= 154)
		{
			this->coord.setPositionX(this->coord.getPositionX() - 1);
		}
	}
	this->putVaisseau();
	this->removeVaisseau(key);
}

void GrosVaisseau::putVaisseau() const
{
	UIKit::color(7);
	unsigned short i = 0;
	unsigned int coordX = this->coord.getPositionX(), coordY = this->coord.getPositionY();
	unsigned int memory1 = coordX;
	while (this->vaisseau[i] != '\0')
	{
		UIKit::gotoXY(coordX, coordY);
		if (this->vaisseau[i] == '\n')
		{
			coordY++;
			coordX = memory1;
		}
		else
		{
			switch (i)
			{
			case(6):
				UIKit::color(7);
				break;
			case(13):
				UIKit::color(4);
				break;
			case(20):
				UIKit::color(7);
				break;
			case(28):
				UIKit::color(4);
				break;
			}
			std::cout << this->vaisseau[i];
			coordX++;
		}
		i++;
	}
}

void GrosVaisseau::removeVaisseau(char key) const
{
	if (key == 'l')
	{
		UIKit::gotoXY(this->coord.getPositionX() - 1, this->coord.getPositionY() + 4);
		std::cout << " ";
	}
	else
	{
		UIKit::gotoXY(this->coord.getPositionX() + 5, this->coord.getPositionY());
		std::cout << " ";
		UIKit::gotoXY(this->coord.getPositionX() + 6, this->coord.getPositionY() + 1);
		std::cout << " ";
		UIKit::gotoXY(this->coord.getPositionX() + 6, this->coord.getPositionY() + 2);
		std::cout << " ";
		UIKit::gotoXY(this->coord.getPositionX() + 7, this->coord.getPositionY() + 3);
		std::cout << " ";
		UIKit::gotoXY(this->coord.getPositionX() + 8, this->coord.getPositionY() + 4);
		std::cout << " ";
	}
}
