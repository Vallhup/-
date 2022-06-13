#pragma once

#define CHAR_SIZE 50
#define HEADING 10
#define SHOOT 10

#include <atlimage.h>
#include <Windows.h>

class Character {
protected:
	// ��ǥ
	int xPos = 0;
	int yPos = 0;

	// �Ŀ�������
	int PwGauge = 0;

	// �ɷ�ġ
	int jump;  // 5 ~ 6
	int speed; // 5 ~ 7
	int power; // 3 ~ 5

	// ����
	int score = 0;

	// Body ����
	int kick = 0;

	CImage PowerGaugeL, PowerGaugeFrameL;
	CImage PowerGaugeR, PowerGaugeFrameR;

public:
	Character();

	RECT CharPos() const;
	void PwGaugeFull();
	int CharScore() const;

	virtual void UI_Print(HDC hdc, int playerNum) const = 0;

	virtual void Draw(HDC hdc, int playerNum) const = 0;
	virtual void Move(int dir, int playerNum) = 0;
	virtual void Jump(int dir) = 0;
	void Kick(int);
	void Goal();
	void Goaled();
	void ResetPos(int);
	~Character();
};

