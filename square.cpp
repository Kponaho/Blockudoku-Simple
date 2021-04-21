/*********************************************************************************
Programme: square.cpp
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: Definition des fonctions de l'objet square*
**********************************************************************************/
#include "square.h"

//initialise tout à 0 ou false
square::square()
{
	_value = 0;
	_active = false;
	_color = 7;
	_borderColor = 7;
}

//initialise tout à 0 ou false
square::square(int x, int y, int side, int color, int bdColor, int value, bool active)
{
	setSquare(x, y, side, color, bdColor, value, active);
}

//destructeur initialise tout à 0 ou false
square::~square()
{
	_value = 0;
	_active = false;
	_color = 7;
	_borderColor = 7;
}

//setteur
void square::setValue(int value)
{
	assert(value >= 1 || value <= 25);
	_value = value;
}

void square::setColor(int color)
{
	assert(color >= 0 || color <= 15);
	_color = color;
}

void square::setBorderColor(int bdColor)
{
	assert(bdColor >= 0 || bdColor <= 15);
	_borderColor = bdColor;
}

void square::setActive(bool active)
{
	_active = active;
}

void square::setSquare(int x, int y, int side, int color, int bdColor, int value, bool active)
{
	setCoord(x, y);
	setDimension(side, side);
	setColor(color);
	setBorderColor(bdColor);
	setValue(value);
	setActive(active);
}

//getteur
int square::getValue() const
{
	return _value;
}

int square::getColor() const
{
	return _color;
}

int square::getBorderColor() const
{
	return _borderColor;
}

bool square::isActive() const
{
	return _active;
}

//nouveau draw qui tient compte des couleurs
void square::draw(ostream& out) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
	gotoxy(_coord.getX(), _coord.getY());

	for (int i = 0; i < _w; i++)
		out << "\xFE ";

	for (int i = 0; i < _h - 2; i++) {
		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		out << "\xFE ";

		for (int j = 0; j < _w - 2; j++)
			out << "  ";

		out << "\xFE ";
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);

	for (int i = 0; i < _w; i++)
		cout << "\xFE ";

	gotoxy(_coord.getX() + _w - 2, _coord.getY() + _h / 2);
	cout << " " << _value;

	cout << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	
	
}

//et qui affiche la value au centre si <> 0
void square::drawFull(ostream& out) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
	gotoxy(_coord.getX(), _coord.getY());

	for (int i = 0; i < _w; i++)
		out << "\xFE ";

	for (int i = 0; i < _h - 2; i++) {
		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		out << "\xFE ";
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
		for (int j = 0; j < _w -2; j++)
			out << "\xFE ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
		out << "\xFE ";
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);

	for (int i = 0; i < _w; i++)
		cout << "\xFE ";

	gotoxy(_coord.getX() + _w - 2, _coord.getY() + _h / 2);
	cout << " " << _value;

	cout << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}
