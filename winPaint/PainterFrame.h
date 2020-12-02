#pragma once
#include "Frame.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "Group.h"
#include "Toolbar.h"
#include "SelectRect.h"
enum class Bt_state {
	rect,
	circle,
	line,
	group,
	paste,
	select,
	move,
	remove,
	menu,
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
	void buttonCallback(ButtonComponent* b) override;

	Figure* MakeFigure();
	Figure* FindFigure();

	Group * setGroup(Group* g);
	Group* setGroupMember(Group* g);

	void setSelectRect();
	void removeFigure(SelectRect* r);
private:
	Bt_state bt_state;

	Vector2 _startPos;
	Vector2 _endPos;

	// 응용 버튼들
	RadioButton* rectBt;
	RadioButton* circleBt;
	RadioButton* lineBt;
	RadioButton* groupBt;
	RadioButton* moveBt;

	Button* selectBt;
	Button* copyBt;
	Button* removeBt;

	Button* menuBt;

	// 응용 변수
	list<Figure*> _figures;
	Figure* _clickFigure;

	SelectRect* _selectRect;

	//list<Figure*> _remove_figures;

};

