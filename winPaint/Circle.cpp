#include "Circle.h"

Circle::Circle(Vector2 v1, Vector2 v2)
{
	_position = Vector2(min(v1.x, v2.x), min(v1.y, v2.y));
	float size = max(abs(v1.x - v2.x), abs(v1.y - v2.y));
	_size = Vector2(size,size);

}

void Circle::Draw()
{
	if (!_visible)
		return;
	Graphics::GetInstance()->setPenColor(_color);
	Graphics::GetInstance()->setTransparent(false);
	Graphics::GetInstance()->setFillColor(_fillcolor);

	if (_parent)
		_position = _parent->getPosition() + _distance;

	Graphics::GetInstance()->drawCircle(_position, _size.x);
}

bool Circle::isClick(Vector2 v)
{
	int c_x = (_position.x + _size.x / 2);
	int c_y = (_position.y + _size.x / 2);
	double d = sqrt((c_x - v.x) * (c_x - v.x) + (c_y - v.y) * (c_y - v.y));
	return (d < _size.x / 2);
}

Figure* Circle::copyThis(int d)
{
	Circle* c = new Circle();
	c->_position = _position + Vector2(d, 0);
	c->_size = _size;
	c->setColor(_color);
	c->setFillColor(_fillcolor);

	_copything = c;

	return c;
}
