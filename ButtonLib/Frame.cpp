#include "Frame.h"

// 일단은 전역 변수 1개는 사용한다.
extern Frame* mainWindow;
// 전역함수로는 윈도 메시지 처리 함수가 있다.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (!mainWindow)
		return DefWindowProc(Hw, Msg, wParam, lParam);;
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_RBUTTONUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	case WM_SIZE:
		mainWindow->eventHandler(MyEvent(Msg, wParam, lParam));
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		if (ps.fErase) {
			OutputDebugString(L"배경을 그려야함\n");  // 이 줄은 테스트용이니 나중에 없앤다.
		}
		// MainWindow  객체의 repaint 를 호출한다.

		//Rectangle(hdc, 100, 100, 200, 300);   // 이것도 테스트용이니 없앤다.
		if (mainWindow != nullptr)
			mainWindow->repaint();
		EndPaint(Hw, &ps);

	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame(std::wstring title, int width, int height) {
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWIn", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	_clickBt = nullptr;
}



void Frame::run() {
	Graphics::GetInstance()->setGraphics(hDC_);
	Init();

	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	MSG msg;
	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

bool Frame::eventHandler(MyEvent e)
{
	//버튼을 눌렀으면 true반환
	if (e.isMouseDown())
	{
		if (_clickBt = findClickBt(e.getMousePos()))
		{
			buttonCallback(_clickBt);
			Graphics::GetInstance()->setPenColor(Graphics::RED);
			_clickBt->Draw();
			return true;
		}
	}
	else if (e.isMouseUp())
	{
		if (_clickBt)
		{
			Graphics::GetInstance()->setPenColor(Graphics::BLACK);
			_clickBt->Draw();
			return true;
		}
	}
	return false;
}

void Frame::repaint() {
	//모든 버튼들 다시 그려줌
	Graphics::GetInstance()->setPenColor(Graphics::BLACK);
	for (auto it : _btns)
		it->Draw();
}


void Frame::addButton(Button* bt)
{
	_btns.push_back(bt);
}

void Frame::invalidate()
{
	InvalidateRect(hWnd_, nullptr, true);
}

Button* Frame::findClickBt(Vector2 pos)
{
	for (auto it = _btns.rbegin(); it != _btns.rend(); it++)
	{
		if ((*it)->isClick(pos))
		{
			return (*it);
		}
	}
	return nullptr;
}
