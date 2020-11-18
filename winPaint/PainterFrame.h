#pragma once
#include "Frame.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "Group.h"

enum class Bt_state {
	rect,
	circle,
	line,
	group,
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

	Group * setGroup(Group* g);
	Group* setGroupMember(Group* g);
private:
	Bt_state bt_state;

	Vector2 _startPos;
	Vector2 _endPos;

	// 응용 버튼들
	Button* rectBt;
	Button* circleBt;
	Button* lineBt;
	Button* groupBt;

	// 응용 변수
	list<Figure*> _figures;
	Figure* _clickFigure;

	//list<Figure*> _remove_figures;

};

