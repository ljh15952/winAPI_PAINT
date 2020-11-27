#pragma once
#include "Rect.h"

class SelectRect :
	public Rect
{
private:
	bool _visible = false;
	bool _ismove = false;
protected:
	list<Figure*> _members;
public:
	SelectRect() {};
	SelectRect(Vector2 s, Vector2 e) : Rect(s, e) {};

	void setVisible(bool v) { _visible = v; }
	bool isVisible() { return _visible; }

	void setMove(bool v) { _ismove = v; }
	bool isMove() { return _ismove; }

	void MoveAll(Vector2 p);
	void ListClear();

	virtual void isInside(Figure* fg);
	virtual void addMember(Figure* fg);

	void setBound();

	int getMemberSize() { return _members.size(); }
};

