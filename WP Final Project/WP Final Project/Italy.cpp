#include "Italy.h"

extern RECT WinSize;
extern RECT P1Rect;
extern RECT P2Rect;
extern BOOL CrashCheck;

Italy::Italy(int playerNum) : Character()
{
	Head[0].Load(_T("sprite\\Italy_L.png"));
	Head[1].Load(_T("sprite\\Italy_R.png"));

	Body[0].Load(_T("sprite\\body.png"));
	Body[1].Load(_T("sprite\\kick_L.png"));
	Body[2].Load(_T("sprite\\kick_R.png"));

	flag.Load(_T("sprite\\flag_Italy.png"));

	Power[1].Load(_T("sprite\\Normal_Ball.png"));

	switch (playerNum) {
	case 1:
		xPos = 100;
		Power[0].Load(_T("sprite\\italyPower_L.png"));
		break;

	case 2:
		xPos = 875;
		Power[0].Load(_T("sprite\\italyPower_R.png"));
		break;
	}

	yPos = 630;

	jump = 5;
	speed = 5;
	power = 5;
}

void Italy::UI_Print(HDC hdc, int playerNum) const
{
	HFONT hFont, oldFont;
	TCHAR str[10];

	SetTextColor(hdc, RGB(255, 255, 0));
	_itow(score, str, 10);

	hFont = CreateFont(40, 0, 0, 0, FW_ULTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("????????"));
	oldFont = (HFONT)SelectObject(hdc, hFont);

	switch (playerNum) {
	case 1:
		TextOut(hdc, WinSize.right / 4 + 60, 140, str, lstrlen(str));

		flag.StretchBlt(hdc, 285, 57, 100, 66, SRCCOPY);

		PowerGaugeL.TransparentBlt(hdc, 269 - (248 * PwGauge / 100), 12, 248 * PwGauge / 100, 98, 100 - PwGauge, 0, PwGauge, 30, RGB(255, 255, 255));
		PowerGaugeFrameL.TransparentBlt(hdc, 20, 10, 250, 100, RGB(255, 255, 255));

		break;

	case 2:
		TextOut(hdc, WinSize.right / 4 * 3 - 80, 140, str, lstrlen(str));

		flag.StretchBlt(hdc, 615, 57, 100, 66, SRCCOPY);

		PowerGaugeR.TransparentBlt(hdc, WinSize.right - 269, 12, 248 * PwGauge / 100, 98, 0, 0, PwGauge, 30, RGB(255, 255, 255));
		PowerGaugeFrameR.TransparentBlt(hdc, WinSize.right - 270, 10, 250, 100, RGB(255, 255, 255));

		break;
	}

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}

void Italy::Draw(HDC hdc, int playerNum) const
{
	switch (playerNum) {
	case 1:
		Body[kick].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(255, 0, 0));

		break;

	case 2:
		Body[kick].TransparentBlt(hdc, xPos, yPos, CHAR_SIZE, CHAR_SIZE, RGB(255, 255, 255));
		Head[playerNum - 1].TransparentBlt(hdc, xPos, yPos - 7, CHAR_SIZE, CHAR_SIZE, RGB(255, 0, 0));

		break;
	}
}

void Italy::Move(int dir, int playerNum)
{
	switch (dir) {
	case 1: // ??
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

	case 2: // ??
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

void Italy::Jump(int dir)
{
	if (dir) {
		yPos -= jump;
	}

	else {
		yPos += jump;
	}
}

void Italy::PowerShoot(HDC hdc, int playerNum, double xpos, double ypos)
{
	switch (playerNum) {
	case 1:
		Power[1].TransparentBlt(hdc, xpos - 20, ypos - 30, 60, 60, RGB(255, 0, 0));
		Power[0].TransparentBlt(hdc, xpos - 60, ypos - 40, 70, 70, RGB(255, 0, 42));
		break;

	case 2:
		Power[1].TransparentBlt(hdc, xpos - 10, ypos - 30, 60, 60, RGB(255, 0, 0));
		Power[0].TransparentBlt(hdc, xpos + 10, ypos - 40, 70, 70, RGB(255, 0, 42));
		break;
	}

	PwGauge = 0;
}

Italy::~Italy()
{
	Head[0].Destroy();
	Head[1].Destroy();
	Body[0].Destroy();
	Body[1].Destroy();
	Body[2].Destroy();
	Power[0].Destroy();
	Power[1].Destroy();
	flag.Destroy();
}