#pragma once
#include "Misc.h"
#include "Graphics.h"

class ButtonComponent
{
protected:
	Vector2 _size; //width,height
	std::string _text;
	Vector2 _position;
public:
	ButtonComponent() {};
	virtual void Draw();
	virtual void setBounds(Vector2 pos, Vector2 size) ;
	virtual bool isClick(Vector2 v);
};

