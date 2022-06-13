#pragma once

#define CHAR_SIZE 50
#define HEADING 10
#define SHOOT 10
#define POWERSHOOT 20

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
	int jump = 0;  // 5 ~ 6
	int speed = 0; // 5 ~ 7
	int power = 0; // 3 ~ 5

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
	int PowerGauge() const;

	virtual void UI_Print(HDC hdc, int playerNum) const = 0;
	virtual void PowerShoot(HDC hdc, int playerNum, double xpos, double ypos) = 0;
	virtual void Draw(HDC hdc, int playerNum) const = 0;
	virtual void Move(int dir, int playerNum) = 0;
	virtual void Jump(int dir) = 0;
	void Kick(int);
	void Goal();
	void Goaled();
	void ResetPos(int);
	virtual ~Character();
};

