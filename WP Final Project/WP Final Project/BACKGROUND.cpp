#include <Windows.h>
#include <atlimage.h>
#include "BACKGROUND.h"

extern CImage BackGround;
extern CImage GoalPostR, GoalPostL;

extern RECT WinSize;

extern int Timer_M;
extern int Timer_S;

extern TCHAR Timer[10];

void DrawBG(HDC hdc)
{
	SIZE size;

	BackGround.BitBlt(hdc, 0, 0, 1000, 740, 0, 0, SRCCOPY);
	GoalPostR.TransparentBlt(hdc, 930, 570, 62, 109, 0, 0, 62, 109, RGB(255, 255, 255));
	GoalPostL.TransparentBlt(hdc, 30, 570, 62, 109, 0, 0, 62, 109, RGB(255, 255, 255));

	HFONT hFont, oldFont;

	hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("±º∏≤"));
	oldFont = (HFONT)SelectObject(hdc, hFont);

	GetTextExtentPoint32(hdc, L"TIME", lstrlen(L"TIME"), &size);

	HBRUSH hBrush, oldBrush;

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	RoundRect(hdc, WinSize.right / 2 - 80, 0, WinSize.right / 2 - 0 + size.cx, size.cy, 5, 5);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 255, 255));

	TextOut(hdc, WinSize.right / 2 - 40, 0, L"TIME", lstrlen(L"TIME"));

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);

	hFont = CreateFont(40, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("π‡¿∫∞ÌµÒ"));
	oldFont = (HFONT)SelectObject(hdc, hFont);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 70, 200));

	wsprintf(Timer, L"%d : %02d", Timer_M, Timer_S);
	TextOut(hdc, WinSize.right / 2 - 30, size.cy + 25, Timer, lstrlen(Timer));

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}