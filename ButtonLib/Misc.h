#pragma once
#include "Windows.h"
#include <list>
#include <string>
using namespace std;
class Vector2 {
public:
	Vector2() : x(0), y(0) {};
	Vector2(int _x, int _y) : x(_x), y(_y) {};
	int x, y;
	void operator -= (Vector2 v);
	void operator += (Vector2 v);
	Vector2 operator + (Vector2 v);
	Vector2 operator - (Vector2 v);
};

class MyEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
public:
	MyEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isMouseDown();
	bool isMouseUp();
	bool isShiftDown();
	bool isCtrlDown();
	int getX();
	int getY();
	Vector2 getMousePos();
};


