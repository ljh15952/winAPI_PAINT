#pragma once
#include "Misc.h"
#include "Graphics.h"
#include "Toolbar.h"
#include "Menubar.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;

public:
	Frame(std::wstring, int, int);
	virtual void run();

	virtual bool eventHandler(MyEvent e);
	virtual void repaint();
	virtual void Init() = 0;
	virtual void buttonCallback(ButtonComponent * b) = 0;

	void invalidate();
	Toolbar* _toolbar;
	Menubar* _menubar;
private:
	ButtonComponent* _clickBt;
	ButtonComponent* _clickBt1;
	ButtonComponent* _clickBt2;

	ButtonComponent* _checkBt;
};