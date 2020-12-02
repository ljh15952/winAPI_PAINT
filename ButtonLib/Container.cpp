#include "Container.h"

ButtonComponent* Container::findClickBt(Vector2 pos)
{
	for (auto it = _btlist.rbegin(); it != _btlist.rend(); it++)
	{
		if ((*it)->isClick(pos))
		{
			return (*it);
		}
	}
	return nullptr;
}

void Container::addComponent(ButtonComponent* b)
{
	_btlist.push_back(b);
}

void Container::repaint()
{
	for (auto it : _btlist)
		it->Draw();
}
