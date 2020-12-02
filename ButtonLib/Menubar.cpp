#include "Menubar.h"


void Menubar::setMenuVisible()
{
	for (auto it : _btlist)
	{
		it->setVisible(!it->isVisible());
	}
}
