#pragma once
#include "ButtonComponent.h"
class RadioButton :
	public ButtonComponent
{
private:
public:
	RadioButton() {};
	RadioButton(std::string text) { _text = text; };

	void Draw() override;
	bool isClick(Vector2 v) override;
	void setCheck() override;
	
	void setBounds(Vector2 pos, int size);
};

