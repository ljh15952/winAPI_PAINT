#pragma once
#include "Button.h"
#include "Container.h"
class Toolbar : public Container
{
public:
	void repaint();
	Button* findClickBt(Vector2 pos);
};

