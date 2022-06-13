#pragma once

#define PI      3.141519

#define GRAVITY 0.5
#define FRICTION 0.8

#define		START_X_POS		500		//	���� �ʱ� ���� x�� ��ġ ��ǥ
#define		START_Y_POS		660		//	���� �ʱ� ���� y�� ��ġ ��ǥ

#define		INITIAL_VELOCITY	120	//	���� �ʱ� �ӵ�

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
};