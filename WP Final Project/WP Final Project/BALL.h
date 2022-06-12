#pragma once

#define PI      3.141519

#define		START_X_POS		500		//	공의 초기 시작 x의 위치 좌표
#define		START_Y_POS		660		//	공의 초기 시작 y의 위치 좌표

#define		INITIAL_VELOCITY	120	//	공의 초기 속도

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

	int  BallyPos() const;

	void Draw(HDC hdc);
	void Action(void);
	void Check_Crash(HWND hWnd);
};