#pragma once

#define CHAR_SIZE 50

class Character {
protected:
	// ��ǥ
	int xPos = 0;
	int yPos = 0;

	// �Ŀ�������
	int powerGauge = 0;

	// �ɷ�ġ
	int jump;
	int speed;
	int power;

public:
	Character();

	virtual void UI_Print(HDC hdc, int playerNum) const = 0;
	virtual void Draw(HDC hdc, int playerNum) const = 0;
	virtual void Move(int dir) = 0;
};

class Korea : public Character
{
	CImage Head;
	CImage Body[3];

	// ���
	CImage flag;

	// ����
	int score = 0;

	//
	BOOL move;

public:
	Korea(int playerNum);

	virtual void UI_Print(HDC hdc, int playerNum) const override;
	virtual void Draw(HDC hdc, int playerNum) const override;
	virtual void Move(int dir) override;
};