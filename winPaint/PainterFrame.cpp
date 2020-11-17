#include "PainterFrame.h"

void PainterFrame::Init()
{
	b1 = new Button("Button_1");
	b1->setBounds(Vector2(100, 70), Vector2(100, 50));
	b1->Draw();

	b2 = new Button("Button_2");
	b2->setBounds(Vector2(250, 70), Vector2(100, 50));
	b2->Draw();

	b3 = new Button("Button_3");
	b3->setBounds(Vector2(400, 70), Vector2(100, 50));
	b3->Draw();

	addButton(b1);
	addButton(b2);
	addButton(b3);
}


bool PainterFrame::eventHandler(MyEvent e)
{
	//if (Frame::eventHandler(e)) 버튼을 눌렀을 때 참

	if (Frame::eventHandler(e))
	{
		if (_clickBt == b1)
		{
			OutputDebugString(L"Click Button 1\n");
		}
		else if (_clickBt == b2)
		{
			OutputDebugString(L"Click Button 2\n");
		}
		else if (_clickBt == b3)
		{
			OutputDebugString(L"Click Button 3\n");
		}
	}

	return false;
}

void PainterFrame::repaint()
{
	Frame::repaint(); //버튼들 repaint
	//응용 객체들 repaint
}

