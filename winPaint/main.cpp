#include "PainterFrame.h"
#include <iostream>
#include <exception>
Frame* mainWindow = nullptr;
int main() {
	try {
		mainWindow = new PainterFrame(L"객체프로젝트", 1000, 800);
		mainWindow->run();
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}


/*
TODO 
 Radio Button 과 이들을 묶는 RadioGroup 을 만들되 composite 패턴을 이용하여 conatainer 를 이용한다.
 

  도형(그룹 포함)의 복사 O
  
  이벤트 처리에서 Listener를 활용

  메뉴바 - 메뉴 - 메뉴항목의 구현

- 기타 자신이 객체지향적으로 구현한 내용

이동도 버튼만들기 X
색깔 팔레트 만들기
스포이드 만들기
undo redo 만들기
메뉴 - 색선택,undo,redo, X버튼

_painterframe figures 리스트 객체 해제
->remove했을때
->그룹화 했을 때

객체들 해제

12-2 

*/
