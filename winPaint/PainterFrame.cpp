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

	copyBt = new Button("복사");
	copyBt->setBounds(Vector2(500, 30), Vector2(100, 30));
	copyBt->Draw();

	selectBt = new Button("선택");
	selectBt->setBounds(Vector2(700, 30), Vector2(100, 30));
	selectBt->Draw();

	moveBt = new RadioButton("이동");
	moveBt->setBounds(Vector2(440, 30), 17);
	moveBt->Draw();
	

	_toolbar->addComponent(rectBt);
	_toolbar->addComponent(circleBt);
	_toolbar->addComponent(lineBt);
	_toolbar->addComponent(groupBt);
	_toolbar->addComponent(copyBt);
	_toolbar->addComponent(selectBt);
	_toolbar->addComponent(moveBt);

	_selectRect = new SelectRect;
	_selectRect->setColor(Graphics::GRAY);
	_selectRect->setVisible(false);
}


bool PainterFrame::eventHandler(MyEvent e)
{
	//if (Frame::eventHandler(e)) 버튼을 눌렀을 때 참
	if (Frame::eventHandler(e))
		return false;

	if (e.isMouseDown() && bt_state == Bt_state::move)
	{
		//move start
		_startPos = e.getMousePos();
		_clickFigure = FindFigure();

		if (_selectRect->isVisible()) //선택박스가 보이고 있는 경우
		{
			_selectRect->setVisible(false);
			_selectRect->setMove(false);
			_selectRect->ListClear();
			invalidate();
		}
	}
	else if (e.isMouseUp() && bt_state == Bt_state::move)
	{
		//move end
		_endPos = e.getMousePos();
		if (_clickFigure)
			_clickFigure->addPosition(_endPos - _startPos);
		invalidate();
	}
	else if (e.isMouseDown())
	{
	//	COLORREF c = GetPixel(hDC_, e.getX(), e.getY());
	//	Graphics::GetInstance()->setPenColor(c);
	//	groupBt->Draw();

		//paint start
		_startPos = e.getMousePos();

		if (_selectRect->isVisible()) //선택박스가 보이고 있는 경우
		{
			if (_selectRect->isClick(_startPos)) //선택박스 클릭했으면
			{
				_selectRect->setMove(true); //움직이기 가능
			}
			else //박스 클릭안했을 경우
			{
				_selectRect->setVisible(false);
				_selectRect->setMove(false);
				_selectRect->ListClear();
				invalidate();
			}
		}
	}
	else if (e.isMouseUp())
	{
		//paint end
		_endPos = e.getMousePos();

		if (_selectRect->isMove()) //선택박스 클릭했었으면
		{
			_selectRect->MoveAll(_endPos - _startPos); 
			invalidate();
			//박스 넣고 안에있는애들 멤버로 넣어주기
		}
		else
		{
			Figure* nowFigure = MakeFigure();
			if (nowFigure)
			{
				nowFigure->Draw();
			}
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
	case Bt_state::select:
		setSelectRect();
		bt_state = Bt_state::null;
		break;
	case Bt_state::group:
		fg = setGroup(setGroupMember(new Group(_startPos,_endPos)));
		break;
		//
	case Bt_state::paste:
		///nothing do here
		break;
		//
	}
	return fg;
}

void PainterFrame::setSelectRect()
{
	_selectRect->setBounds(_startPos, _endPos);
	_selectRect->setVisible(true);
	for (auto it : _figures)
		_selectRect->isInside(it);
	_selectRect->setBound();
	_selectRect->Draw();
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
	else if (b == copyBt)
	{
		bt_state = Bt_state::paste;
		//paste here
		if (_selectRect->isVisible())
		{
			list<Figure*> copys = _selectRect->copyAll(_endPos);
			for (auto it : copys)
			{
				_figures.push_back(it);
			}
		}
	}
	else if (b == selectBt)
	{
		bt_state = Bt_state::select;
	}
	else if (b == moveBt)
	{
		bt_state = Bt_state::move;
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
	if (_selectRect->isVisible())
		_selectRect->Draw();
}



