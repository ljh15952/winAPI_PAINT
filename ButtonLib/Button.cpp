#include "Button.h"

void Button::Draw(HDC hdc)
{
	Rectangle(hdc, _position.x, _position.y, _position.x + _size.x, _position.y + _size.y);
	TextOutA(hdc, _position.x + 2, _position.y + 2, _text.c_str(), strlen(_text.c_str()));
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
