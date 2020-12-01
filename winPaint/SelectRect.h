#pragma once
#include "Rect.h"

class SelectRect :
	public Rect
{
private:

protected:
	list<Figure*> _members;
public:
	SelectRect() {};
	SelectRect(Vector2 s, Vector2 e) : Rect(s, e) {};

	void MoveAll(Vector2 p);
	void RemoveAll();
	void ListClear();

	virtual void isInside(Figure* fg);
	virtual void addMember(Figure* fg);

	void setBound();
	int getMemberSize() { return _members.size(); }

	list<Figure*> copyAll(Vector2 v);
};

