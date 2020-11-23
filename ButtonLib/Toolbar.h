#pragma once
#include "Container.h"
class Toolbar : public Container
{
public:
	void repaint();
	ButtonComponent* findClickBt(Vector2 pos);
};

