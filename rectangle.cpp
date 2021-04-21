/*******************************************************************************************
Programme: rectangle.cpp
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: Definition des fonctions de l'objet rectangle*
*********************************************************************************************/
#include "rectangle.h"

rectangle::rectangle()
{
	_w = _h = 0;
}

rectangle::rectangle(int x, int y, int w, int h)
{
	setLargeur(w);
	setHauteur(h);
	setCoord(x, y);
}

rectangle::~rectangle()
{
	_w = _h = 0;
}

int rectangle::getHauteur() const
{
	return _h;
}

int rectangle::getLargeur() const
{
	return _w;
}

rectangle rectangle::getRectangle() const
{
	return *this;
}

point& rectangle::getPosition()
{
	return _coord;
}

void rectangle::setLargeur(int w)
{
	assert(w >= 0);
	_w = w;
}

void rectangle::setHauteur(int h)
{
	assert(h >= 0);
	_h = h;
}

void rectangle::setCoord(int x, int y)
{
	_coord.setPosition(x, y);
}

void rectangle::setDimension(int w, int h)
{
	setLargeur(w);
	setHauteur(h);
}

void rectangle::setRectangle(int x, int y, int w, int h)
{
	setCoord(x, y);
	setLargeur(w);
	setHauteur(h);
}

//Saisi selon le format (x,y) w X h
void rectangle::read(istream& input)
{
	char lettre;

	viderBuffer();
	input >> _coord >> _w >> lettre >> _h;
}

istream& operator>>(istream& input, rectangle& r)
{
	r.read(input);
	return input;
}

void rectangle::print(ostream& output) const
{
	_coord.print(output);
	output << " " << _w << " X " << _h;
}

ostream& operator<<(ostream& output, const rectangle& r)
{
	r.print(output);
	return output;
}

void rectangle::draw(ostream& output) const
{
	gotoxy(_coord.getX(), _coord.getY());

	for (int i = 0; i < _w; i++)
		output << "*";

	for (int i = 0; i < _h - 2; i++) {
		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		output << "*";

		for (int j = 0; j < _w - 2; j++)
			output << " ";

		output << "*";
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);

	for (int i = 0; i < _w; i++)
		cout << "*";
}

int rectangle::surface() const
{
	return _w * _h;
}

int rectangle::perimetre() const
{
	return (_w + _h) * 2;
}

bool rectangle::operator==(const rectangle& r) const
{
	if (surface() == r.surface())
		return true;
	else
		return false;
}

bool rectangle::operator!=(const rectangle& r) const
{
	if (surface() != r.surface())
		return true;
	else
		return false;
}

bool rectangle::operator>(const rectangle& r) const
{
	if (surface() > r.surface())
		return true;
	else
		return false;
}

bool rectangle::operator<(const rectangle& r) const
{
	if (surface() < r.surface())
		return true;
	else
		return false;
}

bool rectangle::operator<=(const rectangle& r) const
{
	if (surface() <= r.surface())
		return true;
	else
		return false;
}

bool rectangle::operator>=(const rectangle& r) const
{
	if (surface() <= r.surface())
		return true;
	else
		return false;
}