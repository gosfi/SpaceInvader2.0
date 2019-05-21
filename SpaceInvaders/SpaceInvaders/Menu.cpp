//implementation de la clase menu
#include "Menu.h"

Menu::Menu(string titre, string* listeChoix, int nbItem, int ligneDebut, int coloneDebut)
{
	SetWindowFullScreen::setFullScreen();
	UIKit::curseurVisible(false);
	char pathToTitle[] = ("string\\stringMenu\\Title.txt");
	pCheminTitre =pathToTitle;	
	char pathToPlay[] = ("string\\stringMenu\\New_game.txt");
	this->pCheminPlay = pathToPlay;
	char pathToOptions[] = ("string\\stringMenu\\Options.txt");
	this->pCheminOptions = pathToOptions;
	char pathToLeaderboards[] = ("string\\stringMenu\\Leaderboards.txt");
	this->pcheminLeaderboards = pathToLeaderboards;
	char pathToQuit[] = ("string\\stringMenu\\Quit.txt");
	this->pCheminQuit = pathToQuit;
	listeChoix[0] = GetTextFile::getTxtFile(pCheminPlay,316);
	listeChoix[1] = GetTextFile::getTxtFile(pCheminOptions, 232);
	listeChoix[2] = GetTextFile::getTxtFile(pcheminLeaderboards, 430);
	listeChoix[3] = GetTextFile::getTxtFile(pCheminQuit,134);
	this->_titre=GetTextFile::getTxtFile(pCheminTitre,250);
	this->_listeChoix = new string[nbItem];
	for(int i=0;i<nbItem;i++)
	{
		this->_listeChoix[i]=listeChoix[i];
	}
	listeChoix;
	this->_nbItem= nbItem;
	this->coinHG.X= coloneDebut;
	this->coinHG.Y= ligneDebut;
	

	//initialiser les positions
	init();
}

void Menu::init()
{
	//initialisation des position et choix
	this->choix=1;
	this->_posActu.X = coinHG.X;
	this->_posActu.Y = coinHG.Y+10;
	this->_posFirst= _posActu;
	this->_posLast= _posFirst;
	this->_posLast.Y= _posFirst.Y+2*(_nbItem-1);
}

Menu::~Menu()
{
	delete []this->_listeChoix;
}

int Menu::afficherMenu()
{
	//setter les positions
	/*
	this->choix=1;
	this->_posActu.X = coinHG.X;
	this->_posActu.Y = coinHG.Y+2;
	this->_posFirst= _posActu;
	this->_posLast= _posFirst;
	this->_posLast.Y= _posFirst.Y+2*(_nbItem-1);
	*/
	COORD posNext=_posActu;
	//dessiner le menu
	do
	{
	gotoXY(coinHG);
	cout<<_titre<<endl;
	for(int i=0; i<_nbItem;i++)
	{
		gotoXY(coinHG.X-200, _posFirst.Y+(200*i));
		cout<<_listeChoix[i]<<endl;
	}
	
	//capter les flèches
	int touche;
	
	//deplacer(_posActu, _posFirst);
	deplacer(_posActu, _posActu);

	do
	{	
		posNext=_posActu;
		touche=_getch();
		if(touche==224)
		{
			touche= _getch();
		}
		//déplacer
		switch(touche){
		case 80:	//touche bas
			if(_posActu.Y==_posLast.Y) //si on est déjà en bas
			{
				deplacer(_posActu, _posFirst);
				_posActu = _posFirst;
				choix=1;

			}
			else
			{
				posNext.Y+=5;
				deplacer(_posActu, posNext);
				_posActu.Y+=5;
				choix++;
			}
			break;	
		case 72:	//touche haut
			if(_posActu.Y==_posFirst.Y) //si on est déjà en haut
			{
				deplacer(_posActu,_posLast);
				_posActu=_posLast;
				choix=_nbItem;
			}
			else
			{
				posNext.Y-=5;
				deplacer(_posActu, posNext);
				_posActu.Y-=5;
				choix--;
			}
			break;
		}

	}
	while(touche !=13);
	
	
	if (choix == 1)
	{
		cout << "Wow!" << endl;
		system("pause");
	}
	else if (choix == 2)
	{
		MenuOptions options;
		options.afficherOptions();
		
	}
	else if(choix==3){
		Leaderboards lead;
		lead.afficherLead();
		system("cls");
	}
	} while (choix!=4);
	//retourner le choix
	
	return choix;
}


void Menu::deplacer(COORD origine, COORD cible){
	//effacer
	UIKit::curseurVisible(false);
	gotoXY(origine);
	
	//dessiner
	gotoXY(cible);
	
}


int Menu::getTailleMax(){
	return 0;
}


void Menu::gotoXY(COORD pos){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void Menu::gotoXY(int c, int l){
	COORD coord;
	coord.X=c;
	coord.Y=l;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
