#include "PainterFrame.h"
#include <iostream>
#include <exception>
Frame* mainWindow = nullptr;
int main() {
	try {
		mainWindow = new PainterFrame(L"��ü������Ʈ", 1000, 800);
		mainWindow->run();
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}


/*
TODO 
 Radio Button �� �̵��� ���� RadioGroup �� ����� composite ������ �̿��Ͽ� conatainer �� �̿��Ѵ�.
 

  ����(�׷� ����)�� ���� O
  
  �̺�Ʈ ó������ Listener�� Ȱ��

  �޴��� - �޴� - �޴��׸��� ����

- ��Ÿ �ڽ��� ��ü���������� ������ ����

�̵��� ��ư����� X
���� �ȷ�Ʈ �����
�����̵� �����
undo redo �����
�޴� - ������,undo,redo, X��ư

_painterframe figures ����Ʈ ��ü ����
->remove������
->�׷�ȭ ���� ��

��ü�� ����

12-2 

*/
