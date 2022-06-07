#pragma once

class Ball {
	// 좌표
	int xPos;
	int yPos;

	// 반지름
	int radius;

	// 공 스킨
	CImage ballSkin[3];

	// 랜덤 값
	int SkinRnd;
public:
	Ball();

	void Draw(HDC hdc);
};