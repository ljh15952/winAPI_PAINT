#include "PainterFrame.h"

void PainterFrame::Init()
{
	bt_state = Bt_state::null;

	rectBt = new Button("사각형");
	rectBt->setBounds(Vector2(10, 30), Vector2(100, 25));
	rectBt->Draw();

	circleBt = new Button("원");
	circleBt->setBounds(Vector2(120, 30), Vector2(100, 25));
	circleBt->Draw();

	lineBt = new Button("선");
	lineBt->setBounds(Vector2(230, 30), Vector2(100, 25));
	lineBt->Draw();

	addButton(rectBt);
	addButton(circleBt);
	addButton(lineBt);
}


bool PainterFrame::eventHandler(MyEvent e)
{
	//if (Frame::eventHandler(e)) 버튼을 눌렀을 때 참
	if (Frame::eventHandler(e))
		return false;

	if (e.isMouseDown() && e.isCtrlDown())
	{
		//move start
		_startPos = e.getMousePos();
		_clickFigure = FindFigure();
	}
	else if (e.isMouseUp() && e.isCtrlDown())
	{
		//move end
		_endPos = e.getMousePos();
		if (_clickFigure)
		{
			_clickFigure->addPosition(_endPos - _startPos);
			invalidate();
		}
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

		Figure * nowFigure = MakeFigure();
		

		if (nowFigure)
		{
			nowFigure->Draw();
		}
	}

	return false;
}

Figure * PainterFrame::MakeFigure()
{
	Figure* fg = nullptr;
	switch (bt_state)
	{
	case Bt_state::rect:
		fg = new Rect(_startPos, _endPos);
		_figures.push_back(fg);
		break;
	case Bt_state::circle:
		fg = new Circle(_startPos, _endPos);
		_figures.push_back(fg);
		break;
	case Bt_state::line:
		fg = new Line(_startPos, _endPos);
		_figures.push_back(fg);
		break;
	}
	return fg;
}

Figure* PainterFrame::FindFigure()
{
	for (auto it = _figures.rbegin(); it != _figures.rend(); it++)
	{
		if ((*it)->isClick(_startPos))
		{
			return (*it);
		}
	}
	return nullptr;
}


void PainterFrame::buttonCallback(Button* b)
{
	if (b == rectBt)
	{
		bt_state = Bt_state::rect;
	}
	else if (b == circleBt)
	{
		bt_state = Bt_state::circle;
	}
	else if (b == lineBt)
	{
		bt_state = Bt_state::line;
	}
}



void PainterFrame::repaint()
{
	//버튼들 repaint
	Frame::repaint(); 
	//응용 객체들 repaint
	for (auto it : _figures)
	{
		it->Draw();
	}
}



