#pragma once
#include "ButtonComponent.h"
class Button : public ButtonComponent
{
public:
	Button() {};
	Button(std::string text) { _text = text; };
	void Draw() override;
	void setBounds(Vector2 pos, Vector2 size) override;
	bool isClick(Vector2 v) override;
	void ClickEvent(MyEvent e)override;
	void setCheck() override {};
};

