#pragma once
#include "Misc.h"

class Button
{
private:
	std::string _text;
	Vector2 _position;
	Vector2 _size; //width,height
public:
	Button() {};
	Button(std::string text) : _text(text) {};
	void Draw(HDC hdc);
	void setBounds(Vector2 pos, Vector2 size);
	bool isClick(Vector2 v);
};

