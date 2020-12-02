#include "Frame.h"

// �ϴ��� ���� ���� 1���� ����Ѵ�.
extern Frame* mainWindow;
// �����Լ��δ� ���� �޽��� ó�� �Լ��� �ִ�.
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
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
		if (ps.fErase) {
			OutputDebugString(L"����� �׷�����\n");  // �� ���� �׽�Ʈ���̴� ���߿� ���ش�.
		}
		// MainWindow  ��ü�� repaint �� ȣ���Ѵ�.

		//Rectangle(hdc, 100, 100, 200, 300);   // �̰͵� �׽�Ʈ���̴� ���ش�.
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
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // ���� �ּ�ȭ �ִ�ȭ ������
		WS_THICKFRAME,  // resize�� �����ϰ�
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	_clickBt = nullptr;
	_checkBt = nullptr;
	_toolbar = new Toolbar;
	_menubar = new Menubar;
}



void Frame::run() {

	Graphics::GetInstance()->setGraphics(hDC_);
	Init();

	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	MSG msg;
	// �⺻ �޽��� �����Դϴ�:
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
	//��ư�� �������� true��ȯ
	if (e.isMouseDown())
	{
		_clickBt1 = _toolbar->findClickBt(e.getMousePos());
		_clickBt2 = _menubar->findClickBt(e.getMousePos());

		_clickBt = (_clickBt1) ? _clickBt1 : _clickBt2;

		if (_clickBt)
		{
			buttonCallback(_clickBt);
			_clickBt->mouseDownEvent();
			return true;
		}
	}
	else if (e.isMouseUp())
	{
		if (_clickBt)
		{
			_clickBt->mouseUpEvent();
			_checkBt = _clickBt;
			invalidate();
			return true;
		}
	}
	return false;
}

void Frame::repaint() {
	//��� ��ư�� �ٽ� �׷���
	if (_checkBt)
	{
		_checkBt->setCheck();
	}
	Graphics::GetInstance()->setPenColor(Graphics::BLACK);
	_toolbar->repaint();
	_menubar->repaint();
}

void Frame::invalidate()
{
	InvalidateRect(hWnd_, nullptr, true);
}

