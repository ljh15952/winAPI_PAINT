#pragma once
#include "Misc.h"
#include "Button.h"
#include "Graphics.h"
#include "Toolbar.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame {
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;

public:
	Frame(std::wstring, int, int);
	virtual void run();

	virtual bool eventHandler(MyEvent e);
	virtual void repaint();
	virtual void Init() = 0;
	virtual void buttonCallback(Button * b) = 0;

	void invalidate();
private:
	Button* _clickBt;
};