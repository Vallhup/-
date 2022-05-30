#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <atlimage.h>
#include <Windows.h>
#include "CHARACTER.h"

Character::Character(int jump, int speed, int power, int xPos, int yPos)
{
	jump = jump;
	speed = speed;
	power = power;
	xPos = xPos;
	yPos = yPos;
	powerGauge = 0;
	score = 0;
}

void Character::UI_Print(HDC hdc, int x, int y)
{
	HFONT hFont, oldFont;
	TCHAR str[10];

	SetTextColor(hdc, RGB(255, 255, 0));
	_itow(score, str, 10);

	hFont = CreateFont(40, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("π‡¿∫∞ÌµÒ"));
	oldFont = (HFONT)SelectObject(hdc, hFont);

	TextOut(hdc, x, y, str, lstrlen(str));

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}