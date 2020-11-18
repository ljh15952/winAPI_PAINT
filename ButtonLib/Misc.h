#pragma once
#include "Windows.h"
#include <list>
#include <string>
using namespace std;
class Vector2 {
public:
	Vector2() : x(0), y(0) {};
	Vector2(float _x, float _y) : x(_x), y(_y) {};
	float x, y;
	void operator -= (Vector2 v);
	void operator += (Vector2 v);
	Vector2 operator + (Vector2 v);
	Vector2 operator - (Vector2 v);
	Vector2 operator + (int v);
	Vector2 operator - (int v);
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


