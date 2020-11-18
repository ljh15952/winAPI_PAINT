#pragma once
#include "Figure.h"
class Line :
	public Figure
{
public:
	Line() {};
	Line(Vector2 v1,Vector2 v2);
	void Draw() override;
	bool isClick(Vector2 v) override { return false; };
};

