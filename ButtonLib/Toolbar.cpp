#include "Toolbar.h"

void Toolbar::addComponent(Button* b)
{
	_btns.push_back(b);
}

void Toolbar::repaint()
{
	for (auto it : _btns)
		it->Draw();
}

Button* Toolbar::findClickBt(Vector2 pos)
{
	for (auto it = _btns.rbegin(); it != _btns.rend(); it++)
	{
		if ((*it)->isClick(pos))
		{
			return (*it);
		}
	}
	return nullptr;
}
