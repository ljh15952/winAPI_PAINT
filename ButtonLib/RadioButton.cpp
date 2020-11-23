#include "RadioButton.h"

void RadioButton::Draw()
{
	ButtonComponent::Draw();
	ButtonComponent::Draw_Text();
	
	OutputDebugString(L"1\n");
	//Graphics::GetInstance()->setTransparent(true);
	ButtonComponent::Draw_Radio();
}

void RadioButton::setBounds(Vector2 pos, int size)
{
	ButtonComponent::setBounds(pos, Vector2(size,size));
	_textPosition += Vector2(20, -5);
}

void RadioButton::setCheck()
{
//	Graphics::GetInstance()->setTransparent(true);
	Graphics::GetInstance()->setFillColor(Graphics::BLUE);
	ButtonComponent::Draw_Radio();
}

bool RadioButton::isClick(Vector2 v)
{
	return ButtonComponent::isClick(v);
}

void RadioButton::ClickEvent(MyEvent e)
{
	ButtonComponent::ClickEvent(e);
}
