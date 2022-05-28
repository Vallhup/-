#include <windows.h>
#include <tchar.h>
#include <atlimage.h>

#pragma comment (lib, "msimg32.lib")

HINSTANCE g_hInst;
TCHAR lpszClass[] = TEXT("WP Final Project");

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	if (!hPrevInstance) {
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = (WNDPROC)WndProc;
		WndClass.lpszClassName = lpszClass;
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);
	}
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, 1016, 779, NULL, (HMENU)NULL, hInstance, NULL);		//--- 윈도우 크기 변경 가능
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;

	static CImage BackGround;
	static CImage GoalPostR, GoalPostL;

	switch (iMessage) {
	case WM_CREATE:
		BackGround.Load(_T("BackGround.png"));
		GoalPostR.Load(_T("GoalPost - R.png"));
		GoalPostL.Load(_T("GoalPost - L.png"));

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		BackGround.BitBlt(hdc, 0, 0, 1000, 740, 0, 0, SRCCOPY);
		GoalPostR.TransparentBlt(hdc, 930, 570, 62, 109, 0, 0, 62, 109, RGB(255, 255, 255));
		GoalPostL.TransparentBlt(hdc, 30, 570, 62, 109, 0, 0, 62, 109, RGB(255, 255, 255));

		EndPaint(hWnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}