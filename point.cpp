/**************************************************************************************
Programme: point.cpp
Acteur:	Kponaho Anne-Laure Magnane
Date de création: 07/04/21
But du programme: Definition des fonctions de l'objet point*
**************************************************************************************/
#include "point.h"

point::point()
{
	_x = _y = 0;
	_color = 15;
}

point::point(int x, int y)
{
	_x = x;
	_y = y;
	_color = 15;
}

point::~point()
{
	_x = _y = _color = 0;
}

point::point(const point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
}

void point::setX(int x)
{
	_x = x;
}

void point::setY(int y)
{
	_y = y;
}

void point::setColor(int color)
{
	_color = color;
}

void point::setPosition(int x, int y)
{
	setX(x);
	setY(y);
}

int point::getX() const
{
	return _x;
}

int point::getY() const
{
	return _y;
}

int point::getColor() const
{
	return _color;
}

const point& point::operator=(const point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
	return *this;
}

bool point::operator==(const point& p) const
{
	if (p._x == _x && p._y == _y) {
		return true;
	}
	return false;
}

bool point::operator!=(const point& p) const
{
	return !(operator==(p));
}

point point::operator+(const point& p)
{
	point result; //l’appel de l’operator+ peut se faire aussi
	result._x = _x + p._x;
	result._y = _y + p._y;
	return result;
}

point point::operator-(const point& p)
{
	point result; //l’appel de l’operator+ peut se faire aussi
	result._x = _x - p._x;
	result._y = _y - p._y;
	return result;
}

void point::read(istream& input)
{
	char temp;
	input >> temp >> _x >> temp >> _y >> temp;
}

void point::print(ostream& output) const
{
	output << "(" << _x << "," << _y << ")";
}

void point::draw(ostream& output) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	gotoxy(_x, _y);
	output << "*";				//on dessine une petite étoile, à mettre ds le draw
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

float distance(const point& p1, const point& p2)
{
	return sqrt((p1._x + p2._x) * (p1._y + p2._y));
}

void viderBuffer()
{
	cin.clear();
	cin.seekg(0, ios::end);
	if (!cin.fail())
		cin.ignore();
	else
		cin.clear();
}

istream& operator>>(istream& input, point& p)
{
	p.read(input);
	return input;
}

ostream& operator<<(ostream& output, point& p)
{
	p.print(output);
	return output;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
