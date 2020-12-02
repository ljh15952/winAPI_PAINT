#include "Button.h"

void Button::Draw()
{
	if (!_visible)
		return;
	//Graphics::GetInstance()->setPenColor(Graphics::BLACK);
	ButtonComponent::Draw();
	ButtonComponent::DrawBox();
	ButtonComponent::Draw_Text();
}

void Button::setBounds(Vector2 pos, Vector2 size)
{
	ButtonComponent::setBounds(pos, size);
}

bool Button::isClick(Vector2 v)
{
	return ButtonComponent::isClick(v);
}


