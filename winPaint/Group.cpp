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

Figure* Group::copyThis(int d)
{
	Group* c = new Group();
	c->setPosition(_position + Vector2(d, 0));
	c->setSize(_size);
	c->setColor(_color);
	c->setFillColor(_fillcolor);

	for (auto it : _members)
	{
		c->addMember(it->getCopyThiing());
		c->setChildPos();
	}
	_copything = c;
	return c;
}
