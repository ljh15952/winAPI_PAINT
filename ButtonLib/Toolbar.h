#pragma once
#include "Singleton.h"
#include "Button.h"
class Toolbar :
	public Singleton<Toolbar>
{
private:
	list<Button*> _btns;
public:
	void addComponent(Button* b);
	void repaint();
	Button* findClickBt(Vector2 pos);
};

