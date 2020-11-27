#include "Group.h"



void Group::Draw()
{

	Rect::Draw();
}

void Group::setBound()
{
	SelectRect::setBound();
}

void Group::isInside(Figure* fg)
{
	SelectRect::isInside(fg);
}

void Group::addMember(Figure* f)
{
	f->setParent(this);
	SelectRect::addMember(f);
}

void Group::setChildPos()
{
	for (auto it : _members)
	{
		it->setDistance(_position);
	}
}
