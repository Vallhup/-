#pragma once

#define PI      3.141519

#define GRAVITY 0.5
#define FRICTION 0.8

#include <mmsystem.h>
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

	double BallxPos() const;
	double BallyPos() const;

	void Draw(HDC hdc);
	void Physics(Character* p1, Character* p2);
	void Reset();
	~Ball();
};