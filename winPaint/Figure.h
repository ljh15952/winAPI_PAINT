#pragma once
#include "Misc.h"
#include "Graphics.h"
#include <math.h>

class Figure
{
protected:
	Vector2 _position;
	Vector2 _size;
public:
	Figure() {};

	virtual bool isClick(Vector2 pos) = 0;
	virtual void Draw() = 0;

	void addPosition(Vector2 pos);

	Vector2 getPosition() { return _position; }
	Vector2 getSize() { return _size; }
};

