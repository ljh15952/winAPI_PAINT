#include "ButtonComponent.h"

void ButtonComponent::DrawBox()
{
	Graphics::GetInstance()->drawRectangle(_position, _size);
}

void ButtonComponent::Draw_Text()
{
	Graphics::GetInstance()->drawText(_text, _textPosition);
}

void ButtonComponent::Draw_Radio()
{
	Graphics::GetInstance()->drawCircle(_position, _size.x);
}

void ButtonComponent::Draw()
{
	Graphics::GetInstance()->setTransparent(true);
}

void ButtonComponent::ClickEvent(MyEvent e)
{
	if (e.isMouseDown())
	{
		Graphics::GetInstance()->setPenColor(Graphics::RED);
		setCheck();
		Draw();
	}
	else if (e.isMouseUp())
	{
		Graphics::GetInstance()->setPenColor(Graphics::BLACK);
		Draw();
	}
}

void ButtonComponent::setBounds(Vector2 pos, Vector2 size)
{
	_position = pos;
	_textPosition = pos;
	_size = size;
}

bool ButtonComponent::isClick(Vector2 v)
{
	if (_position.x <= v.x &&
		_position.x + _size.x >= v.x &&
		_position.y <= v.y &&
		_position.y + _size.y >= v.y)
		return true;
	return false;
}
