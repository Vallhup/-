#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <atlimage.h>
#include <Windows.h>
#include "CHARACTER.h"

extern RECT WinSize;

Character::Character()
{
	xPos = 0;
	yPos = 0;
	powerGauge = 0;
	jump = 10;
	speed = 10;
	power = 10;
}

Korea::Korea(int playerNum) : Character()
{
	Head.Load(_T("sprite\\korea.png"));
	Body[0].Load(_T("sprite\\body.png"));

	flag.Load(_T("sprite\\flag_korea.png"));

	switch (playerNum) {
	case 1:
		xPos = 100;
		break;

	case 2:
		xPos = 500;
		break;
	}

	yPos = 630;

	move = FALSE;
}

void Korea::UI_Print(HDC hdc, int playerNum) const
{
	HFONT hFont, oldFont;
	TCHAR str[10];

	SetTextColor(hdc, RGB(255, 255, 0));
	_itow(score, str, 10);

	hFont = CreateFont(40, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("¹àÀº°íµñ"));
	oldFont = (HFONT)SelectObject(hdc, hFont);

	switch (playerNum) {
	case 1:
		TextOut(hdc, WinSize.right / 4 + 60, 140, str, lstrlen(str));

		flag.StretchBlt(hdc, 300, 57, 100, 66, SRCCOPY);

		break;

	case 2:
		TextOut(hdc, WinSize.right / 4 * 3 - 60, 140, str, lstrlen(str));

		flag.StretchBlt(hdc, 630, 57, 100, 66, SRCCOPY);

		break;
	}

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}

void Korea::Draw(HDC hdc, int playerNum) const
{
	switch (playerNum) {
	case 1:
		if (move) {
		}

		else {
			Body[0].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		}

		Head.TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));

		break;

	case 2:

		break;
	}
}

void Korea::Move(int dir)
{
	switch (dir) {
	case 1: // ÁÂ
		xPos -= 10;
		break;

	case 2: // ¿ì
		xPos += 10;
		break;
	}
}