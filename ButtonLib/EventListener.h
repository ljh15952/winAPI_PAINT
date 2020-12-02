#pragma once
#include "Misc.h"
class EventListener
{
public:
	EventListener() {}

	void Update();
	void SetEvent(MyEvent e);

	bool isMouseDown();
	bool isMouseUp();
	bool isShiftDown();
	bool isCtrlDown();
	int getX();
	int getY();
	Vector2 getMousePos();

private:
	MyEvent _event;
};

