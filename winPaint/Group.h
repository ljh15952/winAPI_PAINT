#pragma once
#include "SelectRect.h"
class Group :
	public SelectRect
{
public:
	Group() {};
	Group(Vector2 v1, Vector2 v2) : SelectRect(v1, v2) {}
	void Draw() override;

	void setBound();
	void isInside(Figure* fg) override;
	void addMember(Figure* f) override;
	void setChildPos();

	Figure* copyThis(int d) override;
};

