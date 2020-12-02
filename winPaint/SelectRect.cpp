#include "SelectRect.h"

void SelectRect::Draw()
{
	Rect::Draw();
	for (auto it : _members)
	{
		it->Draw();
	}
}

void SelectRect::MoveAll(Vector2 p)
{
	addPosition(p);
	for (auto it : _members)
	{
		it->addPosition(p);
	}
}

void SelectRect::RemoveAll()
{
	for (auto it : _members)
	{
		it->setVisible(false);
	}
}

void SelectRect::ListClear()
{
	_members.clear();
}

void SelectRect::isInside(Figure* fg)
{
	if (Rect::isClick(fg->getPosition()) && Rect::isClick(fg->getPosition() + fg->getSize()))
		addMember(fg);
}

void SelectRect::addMember(Figure* fg)
{
	_members.push_back(fg);
}

void SelectRect::setBound()
{
	OutputDebugString(L"QWEQWE");
	Vector2 pos(999, 999), size(-999, -999);
	for (auto it : _members)
	{
		pos.x = min(pos.x, it->getPosition().x);
		pos.y = min(pos.y, it->getPosition().y);
	}
	for (auto it : _members)
	{
		size.x = max(size.x, it->getSize().x + it->getPosition().x);
		size.y = max(size.y, it->getSize().y + it->getPosition().y);
	}

	_position = pos - 3;
	_size = size - pos + 5;

}

list<Figure*> SelectRect::copyAll(Vector2 v)
{
	list<Figure*> copys;

	for (auto it : _members)
	{
		copys.push_back(it->copyThis(_size.x));
	}
	return copys;
}

