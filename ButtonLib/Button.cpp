#include "Button.h"

void Button::Draw()
{
	Graphics::GetInstance()->drawRectangle(_position, _size);
	Graphics::GetInstance()->drawText(_text,_position);
}

void Button::setBounds(Vector2 pos, Vector2 size)
{
	_position = pos;
	_size = size;
}

bool Button::isClick(Vector2 v)
{
	if (_position.x <= v.x &&
		_position.x + _size.x >= v.x &&
		_position.y <= v.y &&
		_position.y + _size.y >= v.y)
		return true;
	return false;
}
