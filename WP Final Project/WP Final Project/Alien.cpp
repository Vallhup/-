#include "Alien.h"

extern RECT WinSize;
extern RECT P1Rect;
extern RECT P2Rect;
extern BOOL CrashCheck;

Alien::Alien(int playerNum) : Character()
{
	Head[0].Load(_T("sprite\\Alien_L.png"));
	Head[1].Load(_T("sprite\\Alien_R.png"));

	Body[0].Load(_T("sprite\\body.png"));

	flag.Load(_T("sprite\\flag_Alien.png"));

	switch (playerNum) {
	case 1:
		xPos = 100;
		break;

	case 2:
		xPos = 875;
		break;
	}

	yPos = 630;

	srand((unsigned int)time(NULL));
	/*
	jump = rand() % 10 + 1;
	speed = rand() % 10 + 1;
	power = rand() % 10 + 1;
	*/

	jump = 10;
	speed =10;
	power =10;

	move = FALSE;
}

void Alien::UI_Print(HDC hdc, int playerNum) const
{
	HFONT hFont, oldFont;
	TCHAR str[10];

	SetTextColor(hdc, RGB(255, 255, 0));
	_itow(score, str, 10);

	hFont = CreateFont(40, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("�������"));
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

void Alien::Draw(HDC hdc, int playerNum) const
{
	switch (playerNum) {
	case 1:
		if (move) {
		}

		else {
			Body[0].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		}

		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(255, 0, 0));

		break;

	case 2:
		if (move) {
		}

		else {
			Body[0].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		}

		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(255, 0, 0));


		break;
	}
}

void Alien::Move(int dir, int playerNum)
{
	switch (dir) {
	case 1: // ��
		xPos -= speed;

		if (xPos <= 75) {
			xPos = 75;
		}

		if (CrashCheck) {
			switch (playerNum)
			{
			case 1:
				xPos = P2Rect.left - CHAR_SIZE -1;
				break;

			case 2:
				break;
			}
			CrashCheck = FALSE;
		}

		break;

	case 2: // ��
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
				break;
			}
			CrashCheck = FALSE;
		}

		break;
	}
}

void Alien::Jump(int dir)
{
	if (dir) {
		yPos -= jump;
	}

	else {
		yPos += jump;
	}
}