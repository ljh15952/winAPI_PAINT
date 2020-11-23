#pragma once
#include "Misc.h"
#include "Button.h"
#include "RadioButton.h"
class Container
{
public:
	list<ButtonComponent*> _btlist;
	void addComponent(ButtonComponent* b) { _btlist.push_back(b); };
};

