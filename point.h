/**************************************************************************************
Programme: point.h
Acteur:	Kponaho Anne-Laure Magnane
Date de cr�ation: 07/04/21
But du programme: objet manipulation de point avec des coordonn�es (x, y et coouleur)
**************************************************************************************/

#pragma once //permet de d�tecter si une librairie a d�j� �t� incluse
#include <iostream>
#include <cassert>
#include <Windows.h>

using namespace std;

class point
{
private:
	int _x, _y;
	int _color;

public:
	//Constructeur
	point();
	point(int x, int y);

	//Destructeur
	~point();

	//Constructeur de copie
	point(const point& p);

	//Setteur
	void setX(int x);
	void setY(int y);
	void setColor(int color);
	void setPosition(int x, int y);

	//Getteur
	int getX() const;
	int getY() const;
	int getColor() const;

	//Op�rateur de surchage
	const point& operator=(const point& p);
	bool operator==(const point& p) const;
	bool operator!=(const point& p) const;
	point operator+(const point& p);
	point operator-(const point& p);

	//Autres m�thodes
	void read(istream& input);
	void print(ostream& output) const;
	void draw(ostream& output) const;


	friend float distance(const point& p1, const point& p2);
};

void viderBuffer();
istream& operator>>(istream& input, point& p);
ostream& operator<<(ostream& output, point& p);
void gotoxy(int xpos, int ypos);

