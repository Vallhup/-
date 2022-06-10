#pragma once

#define CHAR_SIZE 50

#include <atlimage.h>
#include <Windows.h>

class Character {
protected:
	// ��ǥ
	int xPos = 0;
	int yPos = 0;

	// �Ŀ�������
	int powerGauge = 0;

	// �ɷ�ġ
	int jump;  // 5 ~ 6
	int speed; // 8 ~ 10
	int power; // 3 ~ 5

public:
	Character();

	RECT CharPos();

	virtual void UI_Print(HDC hdc, int playerNum) const = 0;
	virtual void Draw(HDC hdc, int playerNum) const = 0;
	virtual void Move(int dir, int playerNum) = 0;
	virtual void Jump(int dir) = 0;
};

