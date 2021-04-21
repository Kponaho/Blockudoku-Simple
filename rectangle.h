/*******************************************************************************************
Programme: rectangle.h
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: objet manipulation de rectangle avec des coordonnées (largeur, hauteur et coord)
*********************************************************************************************/

#pragma once
#include "point.h"
#include <iostream>

using namespace std;

class rectangle
{
protected:
	point _coord;
	int _w;
	int _h;

public:
	//Constructeurs
	rectangle();
	rectangle(int x, int y, int w = 0, int h = 0);

	//Destructeur
	~rectangle();

	//Getteur
	int getLargeur() const;
	int getHauteur() const;
	rectangle getRectangle() const;
	point& getPosition();

	//Setteur
	void setLargeur(int w);
	void setHauteur(int h);
	void setCoord(int x, int y);
	void setDimension(int w, int h);
	void setRectangle(int x, int y, int w = 0, int h = 0);

	//Autres méthodes
	void read(istream& input);
	void print(ostream& output) const;
	void draw(ostream& output) const;
	int surface() const;
	int perimetre() const;

	//Surcharge d'opérateur
	bool operator==(const rectangle& r) const;
	bool operator!=(const rectangle& r) const;
	bool operator<(const rectangle& r) const;
	bool operator>(const rectangle& r) const;
	bool operator<=(const rectangle& r) const;
	bool operator>=(const rectangle& r) const;

};

istream& operator>>(istream& input, rectangle& r);
ostream& operator<<(ostream& output, const rectangle& r);


