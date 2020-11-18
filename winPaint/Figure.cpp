#include "Figure.h"

void Figure::addPosition(Vector2 pos)
{
	_position += pos;
}

void Figure::setColor(COLORREF color)
{
	_color = color;
}

void Figure::setFillColor(COLORREF color)
{
	_fillcolor = color;
}

void Figure::setPosition(Vector2 pos)
{
	_position = pos;
}

void Figure::setParent(Figure* p)
{
	_parent = p;
}

void Figure::setDistance(Vector2 to)
{	
	_distance = _position - to;
}
