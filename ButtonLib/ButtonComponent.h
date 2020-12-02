#pragma once
#include "Misc.h"
#include "Graphics.h"

class ButtonComponent
{
protected:
	Vector2 _size; //width,height
	std::string _text;
	Vector2 _position;
	Vector2 _textPosition;
	bool _visible = true;
public:
	ButtonComponent() {};
	void DrawBox();
	void Draw_Text();
	void Draw_Radio();

	virtual void setCheck() {};
	virtual void Draw();
	virtual void setBounds(Vector2 pos, Vector2 size) ;
	virtual bool isClick(Vector2 v);
	void mouseDownEvent();
	void mouseUpEvent();
	void setVisible(bool v);
	bool isVisible() { return _visible; }
};

