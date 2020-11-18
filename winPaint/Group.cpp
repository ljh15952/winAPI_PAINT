#include "Group.h"



void Group::Draw()
{

	Rect::Draw();
}

void Group::setBound()
{
	Vector2 pos(999, 999), size(-999, -999);
	for (auto it : _member)
	{
		pos.x = min(pos.x, it->getPosition().x);
		pos.y = min(pos.y, it->getPosition().y);
	}
	for (auto it : _member)
	{
		size.x = max(size.x, it->getSize().x + it->getPosition().x);
		size.y = max(size.y, it->getSize().y + it->getPosition().y);
	}

	_position = pos - 3;
	_size = size - pos + 5;
}

void Group::isInside(Figure* fg)
{
	if (Rect::isClick(fg->getPosition()) && Rect::isClick(fg->getPosition() + fg->getSize()))
		addGroup(fg);
}

void Group::addGroup(Figure* f)
{
	f->setParent(this);
	//
	f->setColor(Graphics::GREEN);
	//6f->Draw();
	//

	_member.push_back(f);
}

void Group::setChildPos()
{
	for (auto it : _member)
	{
		it->setDistance(_position);
	//	it->Draw();
	}
}
