#include "Button.h"

void Button::Draw()
{
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

void Button::ClickEvent(MyEvent e)
{
	ButtonComponent::ClickEvent(e);
}
