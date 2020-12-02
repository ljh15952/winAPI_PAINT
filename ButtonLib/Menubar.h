#pragma once
#include "Container.h"
class Menubar :
	public Container
{
public:
	Menubar() { _visible = true; }
	void setMenuVisible();
};

