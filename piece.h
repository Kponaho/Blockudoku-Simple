/**************************************************************************************
Programme: piece.h
Acteur:	Kponaho Anne-Laure Magnane
Date de cr�ation: 17/04/21
But du programme: Objet piece qui manipule les pieces servant a remplir la grille*
**************************************************************************************/

#pragma once //permet de d�tecter si une librairie a d�j� �t� incluse
#include <iostream>
#include <cassert>
#include <Windows.h>
#include "square.h"

class piece
{
private:
	square _piece[2][2]; //pi�ce pouvant avoir 1, 2, 3 ou 4 morceaux
public:
	//initialise le square � line, col avec le square q (assert pour line et col)
	void setPiece(int line, int col, const square& q);
	void setPieceActive(bool val1, bool val2, bool val3, bool val4);

	//retourne le square � line, col (assert pour line et col)
	const square& getPiece(int line, int col) const;
	
	void draw(ostream& out)const; //draw les 4 morceaux de la pi�ce
};
ostream& operator<<(ostream& out, const piece& p);
