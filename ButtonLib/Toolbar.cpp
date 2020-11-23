#include "Toolbar.h"

/*
�����̳ʴ� ������Ʈ�� ����
��ư,����Ʈ �� ������Ʈ
�����̳ʴ� ������Ʈ ������ �������
������Ʈ�� xy ���������� draw�Լ� �����Լ�Ŭ���޾Ѵ���
�����̳ʿ��� ��ӹ޾Ƽ� ���ٸ� �����
������Ʈ���� ��ӹ޾Ƽ� ��ư�� �����
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
