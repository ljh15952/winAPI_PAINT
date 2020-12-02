#include "EventListener.h"

void EventListener::Update()
{

}

void EventListener::SetEvent(MyEvent e)
{
	_event = e;
}

bool EventListener::isMouseDown()
{
	return _event.msg_ == WM_LBUTTONDOWN;
}

bool EventListener::isMouseUp()
{
	return  _event.msg_ == WM_LBUTTONUP;
}

int EventListener::getX()
{
	return LOWORD(_event.lParam_);
}

int EventListener::getY()
{
	return HIWORD(_event.lParam_);
}

Vector2 EventListener::getMousePos()
{
	return Vector2(LOWORD(_event.lParam_), HIWORD(_event.lParam_));
}

bool EventListener::isShiftDown()
{
	return _event.wParam_ & MK_SHIFT;
}

bool EventListener::isCtrlDown()
{
	return _event.wParam_ & MK_CONTROL;
}