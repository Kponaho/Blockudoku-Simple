/*******************************************************************************************
Programme: main.cpp
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: Programme principal qui fait appel aux fonctions servant *
*a implementer le jeu*
*********************************************************************************************/

#include "rectangle.h"
#include "square.h"
#include "piece.h"

using namespace std;

//prototype de la fonction
void initGrille(square grilleJeu[5][5], int nbLigne, int nbCol);
void printGrille(square grilleJeu[5][5], int nbLigne, int nbCol);
void initPiece(piece pieceJeu[], int taille);
int nextPiece(piece pieceJeu[], int taille);
int choixCase();
void putPiece(const piece& pieceJeu, square grilleJeu[5][5], int ligne, int col);
bool collisionPiece(const piece& pieceJeu, square grilleJeu[5][5], int ligne, int col);


void main() 
{
	//system("cls");
	
	square grilleJeu[5][5];
	piece pieceJeu[10];

	bool lose = false;
	int score = 0;


	srand(time(nullptr)); //ajouter srand au début du main, il doit être appelé une seule fois
	initGrille(grilleJeu, 5, 5);	//appel de la fonction qui initialise la grille


	while (!lose)	//lose est un bool à false
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Bienvenue dans ce petit jeu ou vous pouvez placer des pieces sur la grille\n"
			<< "mais attention de ne pas choisir un emplacement qui est deja occupe.\n";

		printGrille(grilleJeu, 5, 5);	//appel de la fonction qui print la grille

		initPiece(pieceJeu, 10);	//appel de la fonction qui initialise et qui affiche la piece
		int indicePiece = nextPiece(pieceJeu, 10);
		
		int noCase = choixCase();	//appel de la fonction qui demande le choix de case entre 1 et 25

		int ligne = (noCase - 1) / 5; //ici c’est la division entière
		int col = (noCase - 1) % 5; //ici c’est le reste du modulo

		if (!collisionPiece(pieceJeu[indicePiece], grilleJeu, ligne, col))
		{
			putPiece(pieceJeu[indicePiece], grilleJeu, ligne, col);	//appel de la fonction qui 
													//place la piece dans la grille
			printGrille(grilleJeu, 5, 5);	//appel de la fonction qui initialise la grille
			Sleep(100);
		}
		else
		{
			gotoxy(0, 38);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Cette place est impossible!";
		}
		Sleep(200);
	}
	system("PAUSE>0");
}

//fonction qui initialise la grille
void initGrille(square grilleJeu[5][5], int nbLigne, int nbCol)
{
	for (int i = 0; i < nbLigne; i++)
		for (int j = 0; j < nbCol; j++)
			grilleJeu[i][j].setSquare(j * 8, i * 4 + 3, 5, 9, 9, i * 5 + (j + 1), false);
}

//fonction qui print la grille
void printGrille(square grilleJeu[5][5], int nbLigne, int nbCol)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (grilleJeu[i][j].isActive())
			{
				grilleJeu[i][j].drawFull(cout);
			}
			else
			{
				grilleJeu[i][j].draw(cout);
			}
		}
}

//fonction qui initialise et qui  print la piece
void initPiece(piece pieceJeu[], int taille)
{
	int color = rand() % 13 + 1;	//change la couleur interieur de la piece aleatoirement

	for (int noPiece = 0; noPiece < taille; noPiece++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				pieceJeu[noPiece].setPiece(i, j, square(j * 8, i * 4 + 26, 5, color, 9));

	pieceJeu[0].setPieceActive(true, true, true, true); // gros carré
	pieceJeu[1].setPieceActive(true, true, true, false); // | ⁻
	pieceJeu[2].setPieceActive(true, true, false, true); // ⁻|
	pieceJeu[3].setPieceActive(false, true, true, true); // |
	pieceJeu[4].setPieceActive(true, false, true, true); // | _
	pieceJeu[5].setPieceActive(true, false, true, false); // |
	pieceJeu[6].setPieceActive(true, true, false, false); // --
	pieceJeu[7].setPieceActive(true, false, false, false); // un petit cube
	pieceJeu[8].setPieceActive(false, true, true, false); // /
	pieceJeu[9].setPieceActive(true, false, false, true); // \
	
}


//fonction qui genere l’indice aleatoire et affiche la prochaine piece
int nextPiece(piece pieceJeu[], int taille)
{
	gotoxy(0, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Prochaine piece\n";
	
	int indicePiece = rand() % 10; //générera un nombre entre 0 et 9 et c’est ce qu’on veut
	
	pieceJeu[indicePiece].draw(cout); //voyez si les pièces changent à l’écran
	
	return indicePiece;
}


//fonction qui demande le choix de case entre 1 et 25
int choixCase()
{
	int noCase;

	do
	{
		gotoxy(0, 36);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Choisissez l'endroit ou placer cette piece: ";
		gotoxy(45, 36);
		cin >> noCase;

		gotoxy(0, 36);
		cout << "                                                ";

		gotoxy(0, 37);
		cout << "                                                ";

	} while (noCase < 1 || noCase > 25);
	return noCase;
}


//fonction qui place la piece dans la grille
void putPiece(const piece& pieceJeu, square grilleJeu[5][5], int ligne, int col)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) 
			if (pieceJeu.getPiece(i, j).isActive() && (ligne + i < 5 && col + j < 5))
			{
				grilleJeu[ligne + i][col + j].setColor(pieceJeu.getPiece(i, j).getColor());
				grilleJeu[ligne + i][col + j].setActive(pieceJeu.getPiece(i, j).isActive());
				grilleJeu[ligne + i][col + j].drawFull(cout);
			}
}


//fonction qui vérifie les collisions entre les pieces et retourne 
//vrai s'il y a une piece dans la grille
bool collisionPiece(const piece& pieceJeu, square grilleJeu[5][5], int ligne, int col)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (pieceJeu.getPiece(i,j).isActive())
			{
				if (ligne + i >= 5 || col + j >= 5)
					return true;
				if (grilleJeu[ligne + i][col + j].isActive())
					return true;
			}
	return false;
}
