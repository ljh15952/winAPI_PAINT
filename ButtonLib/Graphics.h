#pragma once
#include "Misc.h"
#include "Singleton.h"
class Graphics : public Singleton<Graphics>
{
private:
	HDC _hdc;
	int lineStyle_ = PS_SOLID;
	int thickness_ = 1;
	COLORREF color_ = RGB(0, 0, 0);
	HPEN defaultPen_;
	HBRUSH defaultBrush_;
	HBRUSH nullBrush_;
public:
	static const COLORREF BLACK = RGB(0, 0, 0);
	static const COLORREF RED = RGB(255, 0, 0);
	static const COLORREF GREEN = RGB(0, 255, 0);
	static const COLORREF BLUE = RGB(0, 0, 255);
	static const COLORREF WHITE = RGB(255, 255, 255);
	static const COLORREF GRAY = RGB(200, 200, 200);
	static const COLORREF YELLOW = RGB(255, 255, 0);
public:
	Graphics() {};
	void setGraphics(HDC hdc);

	void drawRectangle(Vector2 pos, Vector2 size);
	void drawCircle(Vector2 pos, int size);
	void drawLine(Vector2 strat, Vector2 end);
	void drawText(std::string t, Vector2 pos);

	void setPenColor(COLORREF color);
	void setFillColor(COLORREF color);

	void setTransparent(bool);
	void setThickness(int);
	void setLineStyle(int);
};

