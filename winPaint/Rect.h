#pragma once
#include "Figure.h"
class Rect :
	public Figure
{
public:
	Rect() {};
	Rect(Vector2 s,Vector2 e);
	void Draw() override;
	bool isClick(Vector2 v) override;

	void setBounds(Vector2 s, Vector2 e);
};

