#include "Misc.h"


MyEvent::MyEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam)
{
	//  Nothing to do here.
}


bool MyEvent::isMouseDown()
{
	return msg_ == WM_LBUTTONDOWN;
}

bool MyEvent::isMouseUp()
{
	return  msg_ == WM_LBUTTONUP;
}

int MyEvent::getX()
{
	return LOWORD(lParam_);
}

int MyEvent::getY()
{
	return HIWORD(lParam_);
}

Vector2 MyEvent::getMousePos()
{
	return Vector2(LOWORD(lParam_), HIWORD(lParam_));
}

bool MyEvent::isShiftDown()
{
	return  wParam_ & MK_SHIFT;
}

bool MyEvent::isCtrlDown()
{
	return  wParam_ & MK_CONTROL;
}

void Vector2::operator-=(Vector2 v)
{
	x -= v.x;
	y -= v.y;
}

void Vector2::operator+=(Vector2 v)
{
	x += v.x;
	y += v.y;
}

Vector2 Vector2::operator+(Vector2 v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(Vector2 v)
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator+(int v)
{
	return Vector2(x + v,y + v);
}

Vector2 Vector2::operator-(int v)
{
	return Vector2(x - v, y - v);
}

