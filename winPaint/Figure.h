#pragma once
#include "Misc.h"
#include "Graphics.h"
#include <math.h>

class Figure
{
protected:
	Vector2 _position;
	Vector2 _size;
	Vector2 _distance;
	bool _visible = false;
	bool _ismove = false;

	COLORREF _color;
	COLORREF _fillcolor;
	Figure* _parent;

	Figure* _copything;
public:
	Figure() {};

	virtual bool isClick(Vector2 pos) = 0;
	virtual void Draw() = 0;

	void addPosition(Vector2 pos);
	void setColor(COLORREF color);
	void setFillColor(COLORREF color);
	void setPosition(Vector2 pos);
	void setParent(Figure* p);
	void setDistance(Vector2 to);

	void setSize(Vector2 size) { _size = size; }
	void setVisible(bool v) { _visible = v; }
	bool isVisible() { return _visible; }
	void setMove(bool v) { _ismove = v; }
	bool isMove() { return _ismove; }
	Vector2 getPosition() { return _position; }
	Vector2 getSize() { return _size; }
	Figure* getCopyThiing() { return _copything; }

	virtual Figure* copyThis(int d) = 0;
};

