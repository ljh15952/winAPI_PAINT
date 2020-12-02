#include "PainterFrame.h"
#include <gdiplus.h>
void PainterFrame::Init()
{
	bt_state = Bt_state::null;

	rectBt = new RadioButton("�簢��");
	rectBt->setBounds(Vector2(130, 5), 17);
	rectBt->Draw();

	circleBt = new RadioButton("��");
	circleBt->setBounds(Vector2(220, 5), 17);
	circleBt->Draw();

	lineBt = new RadioButton("��");
	lineBt->setBounds(Vector2(310, 5), 17);
	lineBt->Draw();

	groupBt = new RadioButton("�׷�ȭ");
	groupBt->setBounds(Vector2(400, 5), 17);
	groupBt->Draw();

	moveBt = new RadioButton("�̵�");
	moveBt->setBounds(Vector2(490, 5), 17);
	moveBt->Draw();

	copyBt = new Button("����");
	copyBt->setBounds(Vector2(5, 45), Vector2(100, 30));
	copyBt->setVisible(false);
	copyBt->Draw();

	selectBt = new Button("����");
	selectBt->setBounds(Vector2(5, 85), Vector2(100, 30));
	selectBt->setVisible(false);
	selectBt->Draw();

	
	removeBt = new Button("����");
	removeBt->setBounds(Vector2(5, 125), Vector2(100, 30));
	removeBt->setVisible(false);
	removeBt->Draw();

	_toolbar->addComponent(rectBt);
	_toolbar->addComponent(circleBt);
	_toolbar->addComponent(lineBt);
	_toolbar->addComponent(groupBt);
	_toolbar->addComponent(moveBt);

	_menubar->addComponent(copyBt);
	_menubar->addComponent(selectBt);
	_menubar->addComponent(removeBt);

	//�޴��� ���
	menuBt = new Button("�޴�");
	menuBt->setBounds(Vector2(5, 5), Vector2(100, 30));
	menuBt->Draw();
	_toolbar->addComponent(menuBt);

	_selectRect = new SelectRect;
	_selectRect->setColor(Graphics::GRAY);
	_selectRect->setVisible(false);
}


bool PainterFrame::eventHandler(MyEvent e)
{
	//if (Frame::eventHandler(e)) ��ư�� ������ �� ��
	if (Frame::eventHandler(e))
		return false;

	if (e.isMouseDown() && bt_state == Bt_state::move)
	{
		//move start
		_startPos = e.getMousePos();
		_clickFigure = FindFigure();

		if (_selectRect->isVisible()) //���ùڽ��� ���̰� �ִ� ���
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

		if (_selectRect->isVisible()) //���ùڽ��� ���̰� �ִ� ���
		{
			if (_selectRect->isClick(_startPos)) //���ùڽ� Ŭ��������
			{
				_selectRect->setMove(true); //�����̱� ����
			}
			else //�ڽ� Ŭ�������� ���
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

		if (_selectRect->isMove()) //���ùڽ� Ŭ���߾�����
		{
			_selectRect->MoveAll(_endPos - _startPos); 
			invalidate();
			//�ڽ� �ְ� �ȿ��ִ¾ֵ� ����� �־��ֱ�
		}
		else
		{
			Figure* nowFigure = MakeFigure();
			if (nowFigure)
			{
				nowFigure->setVisible(true);
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
	case Bt_state::remove:

		break;
	case Bt_state::menu:
	
		break;
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

void PainterFrame::removeFigure(SelectRect* r)
{
	for (auto it : r->getMembers())
	{
		_figures.remove(it);
	}
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

//	removeFigure(g);

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
				it->setVisible(true);
				_figures.push_back(it);
			}
		}
		_menubar->setMenuVisible();
		invalidate();
	}
	else if (b == selectBt)
	{
		bt_state = Bt_state::select;
		_menubar->setMenuVisible();
		invalidate();
	}
	else if (b == moveBt)
	{
		bt_state = Bt_state::move;
	}
	else if (b == removeBt)
	{
		bt_state = Bt_state::remove;
		if (_selectRect->isVisible())
		{
			_selectRect->RemoveAll();
			removeFigure(_selectRect);
		}
		_menubar->setMenuVisible();
		invalidate();
	}
	else if (b == menuBt)
	{
		bt_state = Bt_state::menu;
		_menubar->setMenuVisible();
		invalidate();
	}
}



void PainterFrame::repaint()
{
	//��ư�� repaint
	Frame::repaint(); 
	//���� ��ü�� repaint
	for (auto it : _figures)
	{
		it->Draw();
	}
	if (_selectRect->isVisible())
		_selectRect->Draw();
}



