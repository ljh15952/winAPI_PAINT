#pragma once
#include "Frame.h"
class PainterFrame :
	public Frame
{
public:
	PainterFrame(std::wstring str, int w, int h) : Frame(str, w, h) {}
	void Init() override;
	bool eventHandler(MyEvent e) override;
	void repaint() override;
private:
	// 응용 버튼들
	Button* b1;
	Button* b2;
	Button* b3;
	// 응용 변수
};

