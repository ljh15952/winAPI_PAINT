#pragma once
#include "Misc.h"
#include "Button.h"
#include "Graphics.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame {
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;

	Button* _clickBt;
public:
	Frame(std::wstring, int, int);
	virtual void run();

	virtual bool eventHandler(MyEvent e);
	virtual void repaint();
	virtual void Init() = 0;

	void addButton(Button* bt);
	void invalidate();
	Button* findClickBt(Vector2 pos);
private:
	list<Button*> _btns;
};