#pragma once

#define CHAR_SIZE 50

class Character {
protected:
	// 좌표
	int xPos = 0;
	int yPos = 0;

	// 파워게이지
	int powerGauge = 0;

	// 능력치
	int jump;  // 5 ~ 6
	int speed; // 8 ~ 10
	int power;

public:
	Character();

	virtual void UI_Print(HDC hdc, int playerNum) const = 0;
	virtual void Draw(HDC hdc, int playerNum) const = 0;
	virtual void Move(int dir) = 0;
	virtual void Jump(int dir) = 0;
};

class Korea : public Character
{
	CImage Head[2];
	CImage Body[3];

	// 깃발
	CImage flag;

	// 점수
	int score = 0;

	//
	BOOL move;

public:
	Korea(int playerNum);

	virtual void UI_Print(HDC hdc, int playerNum) const override;
	virtual void Draw(HDC hdc, int playerNum) const override;
	virtual void Move(int dir) override;
	virtual void Jump(int dir) override;
};