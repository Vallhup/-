#include <windows.h>
#include <tchar.h>
#include <atlimage.h>

#include "BACKGROUND.h"
#include "BALL.h"
#include "CHARACTER.h"

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

CImage BackGround;
CImage GoalPostR, GoalPostL;

RECT WinSize;

int Timer_M = 1;
int Timer_S = 0;

TCHAR Timer[10];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;

	static HBITMAP hBitmap;

	Character P1 = { 0, 0, 0, 0, 0 };
	Character P2 = { 0, 0, 0, 0, 0 };

	switch (iMessage) {
	case WM_CREATE:
		BackGround.Load(_T("BackGround.png"));
		GoalPostR.Load(_T("GoalPost - R.png"));
		GoalPostL.Load(_T("GoalPost - L.png"));

		GetClientRect(hWnd, &WinSize);

		Timer_M = 1;
		Timer_S = 0;

		SetTimer(hWnd, 1, 1000, NULL);

		break;

	case WM_TIMER:
		switch (LOWORD(wParam)) {
		case 1:
			if (Timer_M == 1) {
				Timer_M = 0;
				Timer_S = 59;
			}

			else if(Timer_M == 0) {
				if (--Timer_S == 0) {
					KillTimer(hWnd, 1);
				}
			}
	
			break;
		}

		InvalidateRect(hWnd, NULL, FALSE);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		hBitmap = CreateCompatibleBitmap(hdc, WinSize.right, WinSize.bottom);
		memdc = CreateCompatibleDC(hdc);

		(HBITMAP)SelectObject(memdc, hBitmap);

		DrawBG(memdc);

		P1.UI_Print(memdc, WinSize.right / 4 + 60, 140);
		P2.UI_Print(memdc, WinSize.right / 4 * 3 - 60, 140);

		BitBlt(hdc, 0, 0, 1000, 800, memdc, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}