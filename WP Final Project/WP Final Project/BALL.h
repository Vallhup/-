#pragma once

#define PI      3.141519

#define GRAVITY 0.5
#define FRICTION 0.8

#include "CHARACTER.h"

class Ball {
	// 좌표
	double xPos;
	double yPos;

	// 속도
	double xVel;
	double yVel;

	// 반지름
	int radius;

	// 공 스킨
	CImage ballSkin[3];

	// 랜덤 값
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