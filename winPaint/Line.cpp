#include "Line.h"

Line::Line(Vector2 v1, Vector2 v2)
{
	_position = v1;
	_size = v2;
}

void Line::Draw()
{
	Graphics::GetInstance()->setPenColor(Graphics::BLUE);
	Graphics::GetInstance()->setTransparent(true);
	Graphics::GetInstance()->drawLine(_position, _size);
}
