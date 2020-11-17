//#pragma once
//#include "Singleton.h"
//class Graphics : public Singleton<Graphics>
//{
//private:
//	HDC hdc_;
//	int lineStyle_ = PS_SOLID;
//	int thickness_ = 1;
//	COLORREF color_ = RGB(0, 0, 0);
//	HPEN defaultPen_;
//	HBRUSH defaultBrush_;
//	HBRUSH nullBrush_;
//public:
//	static const COLORREF BLACK = RGB(0, 0, 0);
//	static const COLORREF RED = RGB(255, 0, 0);
//	static const COLORREF GREEN = RGB(0, 255, 0);
//	static const COLORREF BLUE = RGB(0, 0, 255);
//	static const COLORREF WHITE = RGB(255, 255, 255);
//	static const COLORREF GRAY = RGB(200, 200, 200);
//	static const COLORREF YELLOW = RGB(255, 255, 0);
//public:
//	Graphics() {};
//	void rectangle(int, int, int, int);
//	void ellipse(int, int, int, int);
//	void line(int, int, int, int);
//	void text(std::string, int, int);
//	void setColor(COLORREF);
//	void setFill(COLORREF color);
//	void setTransparent(bool);
//	void setThickness(int);
//	void setLineStyle(int);
//};
//
