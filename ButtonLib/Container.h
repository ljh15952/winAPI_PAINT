#pragma once
#include "Misc.h"
#include "Button.h"
class Container
{
public:
	list<Button*> _btlist;
	void addComponent(Button* b) { _btlist.push_back(b); };
};

