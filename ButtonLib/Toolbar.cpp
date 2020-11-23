#include "Toolbar.h"

/*
컨테이너는 컴포넌트를 포함
버튼,리스트 다 컴포넌트
컨테이너는 컴포넌트 가지고 있으면댐
컴포넌트는 xy 생성자정도 draw함수 가상함수클릭받앗는지
컨테이너에서 상속받아서 툴바를 만들어
컴포넌트에서 상속받아서 버튼을 만들어
*/


void Toolbar::repaint()
{
	for (auto it : _btlist)
		it->Draw();
}

ButtonComponent* Toolbar::findClickBt(Vector2 pos)
{
	for (auto it = _btlist.rbegin(); it != _btlist.rend(); it++)
	{
		if ((*it)->isClick(pos))
		{
			return (*it);
		}
	}
	return nullptr;
}
