#include "PainterFrame.h"

void PainterFrame::Init()
{
	bt_state = Bt_state::null;

	rectBt = new Button("사각형");
	rectBt->setBounds(Vector2(10, 30), Vector2(100, 25));
	rectBt->Draw();

	b2 = new Button("Button_2");
	b2->setBounds(Vector2(120, 30), Vector2(100, 25));
	b2->Draw();

	b3 = new Button("Button_3");
	b3->setBounds(Vector2(230, 30), Vector2(100, 25));
	b3->Draw();

	addButton(rectBt);
	addButton(b2);
	addButton(b3);
}


bool PainterFrame::eventHandler(MyEvent e)
{
	//if (Frame::eventHandler(e)) 버튼을 눌렀을 때 참
	if (Frame::eventHandler(e))
		return false;

	if (e.isMouseDown() && e.isCtrlDown())
	{
		//move start
	}
	else if (e.isMouseUp() && e.isCtrlDown())
	{
		//move end
	}
	else if (e.isMouseDown())
	{
		//paint start
		_startPos = e.getMousePos();
	}
	else if (e.isMouseUp())
	{
		//paint end
		_endPos = e.getMousePos();

		if (bt_state == Bt_state::rect)
		{
			_figures.push_back(new Rect(_startPos, _endPos));
		}

		if (_figures.size() > 0)
		{
			_figures.back()->Draw();
		}
	}

	return false;
}

void PainterFrame::buttonCallback(Button* b)
{
	if (b == rectBt)
	{
		bt_state = Bt_state::rect;
	}
}


void PainterFrame::repaint()
{
	Frame::repaint(); //버튼들 repaint
	//응용 객체들 repaint
	for (auto it : _figures)
	{
		it->Draw();
	}
}



