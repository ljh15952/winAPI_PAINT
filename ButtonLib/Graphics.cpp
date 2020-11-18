#include "Graphics.h"

void Graphics::setGraphics(HDC hdc)
{
	_hdc = hdc;
	defaultPen_ = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	defaultBrush_ = CreateSolidBrush(RGB(255, 255, 255));
	nullBrush_ = (HBRUSH)GetStockObject(NULL_BRUSH);
}

void Graphics::drawRectangle(Vector2 pos, Vector2 size)
{
	Rectangle(_hdc, pos.x, pos.y, pos.x + size.x, pos.y + size.y);
}
void Graphics::drawCircle(Vector2 pos, int size)
{
	Ellipse(_hdc, pos.x, pos.y, pos.x + size, pos.y + size);
}
void Graphics::drawLine(Vector2 strat, Vector2 end)
{
	MoveToEx(_hdc, strat.x, strat.y, NULL);
	LineTo(_hdc, strat.x + end.x, strat.y + end.y);
}
void Graphics::drawText(std::string t, Vector2 pos)
{
	TextOutA(_hdc, pos.x + 5, pos.y + 5, t.c_str(), strlen(t.c_str()));
}
void Graphics::setPenColor(COLORREF color) {
	HPEN hpen = ::CreatePen(lineStyle_, thickness_, color);
	HPEN oldPen = (HPEN) ::SelectObject(_hdc, hpen);
	DeleteObject(oldPen);
}

void Graphics::setFillColor(COLORREF color) {
	HBRUSH hbrush = ::CreateSolidBrush(color);
	HBRUSH oldBrush = (HBRUSH) ::SelectObject(_hdc, hbrush);
	DeleteObject(oldBrush);
}

void Graphics::setThickness(int n) {
	thickness_ = n;
}
void Graphics::setLineStyle(int n) {
	lineStyle_ = n;  // 
}

void Graphics::setTransparent(bool b) {
	if (b) {
		SelectObject(_hdc, nullBrush_);
	}
	else {
		SelectObject(_hdc, defaultBrush_);
	}
}