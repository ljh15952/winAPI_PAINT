#pragma once
#include "Figure.h"
class Circle :
	public Figure
{
public:
	Circle() {};
	Circle(Vector2 v1,Vector2 v2);
	void Draw() override;
	bool isClick(Vector2 v) override;

	Figure* copyThis(int d) override;
};

