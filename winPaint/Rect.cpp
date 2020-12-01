#include "Rect.h"

Rect::Rect(Vector2 s, Vector2 e)
{
	_position = Vector2(min(s.x, e.x), min(s.y, e.y));
	_size = Vector2(abs(s.x - e.x), abs(s.y - e.y));
}

void Rect::Draw()
{
	if (!_visible)
		return;
	Graphics::GetInstance()->setPenColor(_color);
	Graphics::GetInstance()->setTransparent(true);

	if (_parent)
		_position = _parent->getPosition() + _distance;
	Graphics::GetInstance()->drawRectangle(_position, _size);
}



bool Rect::isClick(Vector2 p)
{
	if (_position.x <= p.x &&
		_position.x + _size.x >= p.x &&
		_position.y <= p.y &&
		_position.y + _size.y >= p.y)
		return true;
	return false;
}

void Rect::setBounds(Vector2 s, Vector2 e)
{
	_position = Vector2(min(s.x, e.x), min(s.y, e.y));
	_size = Vector2(abs(s.x - e.x), abs(s.y - e.y));
}

Figure* Rect::copyThis(int d)
{
	Rect* c = new Rect();
	c->_position = _position + Vector2(d,0);
	c->_size = _size;
	c->setColor(_color);
	c->setFillColor(_fillcolor);
	_copything = c;

	return c;
}

