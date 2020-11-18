#include "Rect.h"

Rect::Rect(Vector2 s, Vector2 e)
{
	_position = Vector2(min(s.x, e.x), min(s.y, e.y));
	_size = Vector2(abs(s.x - e.x), abs(s.y - e.y));
}

void Rect::Draw()
{
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
