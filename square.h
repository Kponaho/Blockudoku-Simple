/*********************************************************************************
Programme: square.h
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: L'objet square implémente Le jeu blockudoku en console où *
* on dessine la grille est  qui servira au jeu et l'activité de certain pieces*
**********************************************************************************/

#pragma once

#include "rectangle.h"
#include <cassert>
#include <iostream>
#include <windows.h>

using namespace std;

class square : public rectangle {
private:
	int _value; //value de la square
	bool _active; //servira pour nos pièces
	int _color; //couleur de la square entre 1 et 15 inclus.. À valider assert
	int _borderColor; //couleur de la bordure de la square entre 1 et 15 inclus..

public:
	square(); //initialise tout à 0 ou false
	square(int x, int y, int side, int color = 0, int bdColor = 0, int value = 0, bool active = true);
	~square(); //initialise tout à 0 ou false
	
	//setteur
	void setValue(int value);
	void setColor(int color);
	void setBorderColor(int bdColor);
	void setActive(bool active);
	void setSquare(int x, int y, int side, int color = 0, int bdColor = 0, int value = 0, bool active = true);
	
	//getteur
	int getValue()const;
	int getColor()const;
	int getBorderColor() const;
	
	//methode
	bool isActive()const;
	
	void draw(ostream& out)const; //nouveau draw qui tient compte des couleurs
	void drawFull(ostream& out) const; //et qui affiche la value au centre si <> 0
};