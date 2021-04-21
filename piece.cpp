/**************************************************************************************
Programme: piece.cpp
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 17/04/21
But du programme: Definition des fonctions de l'objet piece*
**************************************************************************************/

#include "piece.h"

void piece::setPiece(int line, int col, const square& q)
{
	assert(line >= 0 && line < 2);
	assert(col >= 0 && col < 2);
	_piece[line][col] = q;
}

void piece::setPieceActive(bool val1, bool val2, bool val3, bool val4)
{
	_piece[0][0].setActive(val1);
	_piece[0][1].setActive(val2);
	_piece[1][0].setActive(val3);
	_piece[1][1].setActive(val4);
}

const square& piece::getPiece(int line, int col) const
{
	assert(line >= 0 && line < 2);
	assert(col >= 0 && col < 2);
	return _piece[line][col];
}

void piece::draw(ostream& out) const
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (_piece[i][j].isActive())
				_piece[i][j].drawFull(cout);
	
}

ostream& operator<<(ostream& out, const piece& p)
{
	p.draw(out);
	return out;
}
