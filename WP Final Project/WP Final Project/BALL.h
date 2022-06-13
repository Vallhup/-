#pragma once

#define PI      3.141519

#define GRAVITY 0.5
#define FRICTION 0.8

#include "CHARACTER.h"

class Ball {
	// ��ǥ
	double xPos;
	double yPos;

	// �ӵ�
	double xVel;
	double yVel;

	// ������
	int radius;

	// �� ��Ų
	CImage ballSkin[3];

	// ���� ��
	int SkinRnd;
public:
	Ball();

	double BallyPos() const;

	void Draw(HDC hdc);
	void Action(void);
	void Check_Crash(HWND hWnd);
	void Physics(Character* p1, Character* p2);
	void Reset();
	~Ball();
};