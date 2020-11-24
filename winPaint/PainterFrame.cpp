#include "PainterFrame.h"
#include <gdiplus.h>
void PainterFrame::Init()
{
	bt_state = Bt_state::null;

	rectBt = new RadioButton("사각형");
	rectBt->setBounds(Vector2(10, 30), 17);
	rectBt->Draw();

	circleBt = new RadioButton("원");
	circleBt->setBounds(Vector2(120, 30), 17);
	circleBt->Draw();

	lineBt = new RadioButton("선");
	lineBt->setBounds(Vector2(230, 30), 17);
	lineBt->Draw();

	groupBt = new RadioButton("그룹화");
	groupBt->setBounds(Vector2(340, 30), 17);
	groupBt->Draw();

	_toolbar->addComponent(rectBt);
	_toolbar->addComponent(circleBt);
	_toolbar->addComponent(lineBt);
	_toolbar->addComponent(groupBt);
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
	//	COLORREF c = GetPixel(hDC_, e.getX(), e.getY());
	//	Graphics::GetInstance()->setPenColor(c);
	//	groupBt->Draw();

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
		fg->setColor(Graphics::RED);
		_figures.push_back(fg);
		break;
	case Bt_state::circle:
		fg = new Circle(_startPos, _endPos);
		fg->setColor(Graphics::GREEN);
		fg->setFillColor(Graphics::YELLOW);
		_figures.push_back(fg);
		break;
	case Bt_state::line:
		fg = new Line(_startPos, _endPos);
		fg->setColor(Graphics::BLUE);
		_figures.push_back(fg);
		break;
	case Bt_state::group:
		fg = setGroup(setGroupMember(new Group(_startPos,_endPos)));
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

Group * PainterFrame::setGroup(Group* g)
{
	if (g->getMemberSize() <= 0)
		return nullptr;

	g->setColor(Graphics::GRAY);
	g->setBound();
	g->setChildPos();
	_figures.push_back(g);
	return g;
}

Group* PainterFrame::setGroupMember(Group* g)
{
	for (auto it : _figures)
		g->isInside(it);
	return g;
}


void PainterFrame::buttonCallback(ButtonComponent* b)
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
	else if (b == groupBt)
	{
		bt_state = Bt_state::group;
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



