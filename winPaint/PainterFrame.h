#pragma once
#include "Frame.h"
#include "Rect.h"

enum class Bt_state {
	rect,
	null
};

class PainterFrame :
	public Frame
{
public:
	PainterFrame(std::wstring str, int w, int h) : Frame(str, w, h) {}
	void Init() override;
	bool eventHandler(MyEvent e) override;
	void repaint() override;
	void buttonCallback(Button* b) override;

	Figure* MakeFigure();
	Figure* FindFigure();
private:
	Bt_state bt_state;

	Vector2 _startPos;
	Vector2 _endPos;

	// ���� ��ư��
	Button* rectBt;
	Button* b2;
	Button* b3;
	// ���� ����
	list<Figure*> _figures;
	Figure* _clickFigure;

};

