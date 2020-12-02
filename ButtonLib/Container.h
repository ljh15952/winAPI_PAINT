#pragma once
#include "Misc.h"
#include "Button.h"
#include "RadioButton.h"
class Container : public ButtonComponent
{
public:
	list<ButtonComponent*> _btlist;

	ButtonComponent* findClickBt(Vector2 pos);
	void addComponent(ButtonComponent* b);
	void repaint();
};

