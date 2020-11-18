#include "Line.h"

Line::Line(Vector2 v1, Vector2 v2)
{
	_position = v1;
	_size = Vector2((v2.x - v1.x), (v2.y - v1.y));
}

void Line::Draw()
{
	Graphics::GetInstance()->setPenColor(_color);
	Graphics::GetInstance()->setTransparent(true);

	if (_parent)
		_position = _parent->getPosition() + _distance;

	Graphics::GetInstance()->drawLine(_position, _size);
}
