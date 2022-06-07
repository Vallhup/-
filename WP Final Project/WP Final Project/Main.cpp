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

void LOOP(HWND, BOOL KB[]);

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
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, 1016, 779, NULL, (HMENU)NULL, hInstance, NULL);		//--- À©µµ¿ì Å©±â º¯°æ °¡´É
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

Character* P1;
Character* P2;

Ball ball;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;

	static HBITMAP hBitmap;

	static BOOL KeyBuffer[256] = {FALSE};

	static int JmpCnt1, JmpCnt2;

	switch (iMessage) {
	case WM_CREATE:
		BackGround.Load(_T("BackGround.png"));
		GoalPostR.Load(_T("GoalPost - R.png"));
		GoalPostL.Load(_T("GoalPost - L.png"));

		P1 = new Korea(1);
		P2 = new Korea(2);

		GetClientRect(hWnd, &WinSize);

		Timer_M = 1;
		Timer_S = 0;

		JmpCnt1 = JmpCnt2 = 0;

		SetTimer(hWnd, 1, 1000, NULL);

		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case 'a': 
		case 'A': // 1p ÁÂ
		case 'd': 
		case 'D': // 1p ¿ì
		case 'w':
		case 'W':
		case VK_LEFT: // 2p ÁÂ
		case VK_RIGHT: // 2p ¿ì
		case VK_UP:
			KeyBuffer[wParam] = TRUE;
			break;
		}

		InvalidateRect(hWnd, NULL, FALSE);

		break;

	case WM_KEYUP:
		switch (wParam)
		{
		case 'a':
		case 'A': // 1p ÁÂ
		case 'd':
		case 'D': // 1p ¿ì
		case 'w':
		case 'W':
		case VK_LEFT: // 2p ÁÂ
		case VK_RIGHT: // 2p ¿ì
		case VK_UP:
			KeyBuffer[wParam] = FALSE;
			break;

		}
		
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

		case 2:
			if (JmpCnt1 <= 8) {
				P1->Jump(1);
			}

			else {
				P1->Jump(0);
			}

			if (JmpCnt1++ == 17) {
				KillTimer(hWnd, 2);
				JmpCnt1 = 0;
			}

			break;

		case 3:
			if (JmpCnt2 <= 8) {
				P2->Jump(1);
			}

			else {
				P2->Jump(0);
			}

			if (JmpCnt2++ == 17) {
				KillTimer(hWnd, 3);
				JmpCnt2 = 0;
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

		LOOP(hWnd, KeyBuffer);

		P1->UI_Print(memdc, 1);
		P2->UI_Print(memdc, 2);

		P1->Draw(memdc, 1);
		P2->Draw(memdc, 2);
		
		ball.Draw(memdc);

		BitBlt(hdc, 0, 0, 1000, 800, memdc, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void LOOP(HWND hWnd, BOOL KB[]) {
	if (KB['a'] || KB['A'])
	{
		P1->Move(1);
	}

	if (KB['d'] || KB['D'])
	{
		P1->Move(2);
	}

	if (KB[VK_LEFT])
	{
		P2->Move(1);
	}

	if (KB[VK_RIGHT])
	{
		P2->Move(2);
	}
	
	if (KB['w'] || KB['W'])
	{
		SetTimer(hWnd, 2, 25, NULL);
	}

	if (KB[VK_UP])
	{
		SetTimer(hWnd, 3, 25, NULL);
	}
}