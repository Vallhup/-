#include "Canada.h"

extern RECT WinSize;
extern RECT P1Rect;
extern RECT P2Rect;
extern BOOL CrashCheck;

Canada::Canada(int playerNum) : Character()
{
	Head[0].Load(_T("sprite\\Canada_L.png"));
	Head[1].Load(_T("sprite\\Canada_R.png"));

	Body[0].Load(_T("sprite\\body.png"));

	flag.Load(_T("sprite\\flag_Canada.png"));

	switch (playerNum) {
	case 1:
		xPos = 100;
		break;

	case 2:
		xPos = 875;
		break;
	}

	yPos = 630;

	jump = 6;
	speed = 9;
	power = 4;

	move = FALSE;
}

void Canada::UI_Print(HDC hdc, int playerNum) const
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

void Canada::Draw(HDC hdc, int playerNum) const
{
	switch (playerNum) {
	case 1:
		if (move) {
		}

		else {
			Body[0].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		}

		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(0, 255, 0));

		break;

	case 2:
		if (move) {
		}

		else {
			Body[0].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		}

		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(0, 255, 0));


		break;
	}
}

void Canada::Move(int dir, int playerNum)
{
	switch (dir) {
	case 1: // ÁÂ
		xPos -= speed;

		if (xPos <= 75) {
			xPos = 75;
		}

		if (CrashCheck) {
			switch (playerNum)
			{
			case 1:
				xPos = P2Rect.left - CHAR_SIZE - 1;
				break;

			case 2:
				xPos = P1Rect.right + 1;
				break;
			}
			CrashCheck = FALSE;
		}

		break;

	case 2: // ¿ì
		xPos += speed;

		if (xPos >= 900) {
			xPos = 900;
		}

		if (CrashCheck) {
			switch (playerNum)
			{
			case 1:
				xPos = P2Rect.left - CHAR_SIZE - 1;
				break;

			case 2:
				xPos = P1Rect.right + 1;
				break;
			}
			CrashCheck = FALSE;
		}

		break;
	}
}

void Canada::Jump(int dir)
{
	if (dir) {
		yPos -= jump;
	}

	else {
		yPos += jump;
	}
}