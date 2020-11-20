#include "Button.h"

void Button::Draw()
{
	ButtonComponent::Draw();
}

void Button::setBounds(Vector2 pos, Vector2 size)
{
	ButtonComponent::setBounds(pos, size);
}

bool Button::isClick(Vector2 v)
{
	return ButtonComponent::isClick(v);
}
