/**************************************************************************************
Programme: piece.h
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 17/04/21
But du programme: Objet piece qui manipule les pieces servant a remplir la grille*
**************************************************************************************/

#pragma once //permet de détecter si une librairie a déjà été incluse
#include <iostream>
#include <cassert>
#include <Windows.h>
#include "square.h"

class piece
{
private:
	square _piece[2][2]; //pièce pouvant avoir 1, 2, 3 ou 4 morceaux
public:
	//initialise le square à line, col avec le square q (assert pour line et col)
	void setPiece(int line, int col, const square& q);
	void setPieceActive(bool val1, bool val2, bool val3, bool val4);

	//retourne le square à line, col (assert pour line et col)
	const square& getPiece(int line, int col) const;
	
	void draw(ostream& out)const; //draw les 4 morceaux de la pièce
};
ostream& operator<<(ostream& out, const piece& p);
