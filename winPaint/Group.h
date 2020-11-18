#pragma once
#include "Rect.h"
class Group :
	public Rect
{
private:
	list<Figure*> _member;
public:
	Group() {};
	Group(Vector2 v1, Vector2 v2) : Rect(v1, v2) {}
	void Draw() override;

	void setBound();
	void isInside(Figure* fg);
	void addGroup(Figure* f);
	void setChildPos();
	int getMemberSize() { return _member.size(); }
};

