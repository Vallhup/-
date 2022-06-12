#pragma once

#define PI      3.141519

#define		START_X_POS		500		//	���� �ʱ� ���� x�� ��ġ ��ǥ
#define		START_Y_POS		660		//	���� �ʱ� ���� y�� ��ġ ��ǥ

#define		INITIAL_VELOCITY	120	//	���� �ʱ� �ӵ�

class Ball {
	// ��ǥ
	int xPos;
	int yPos;

	// ������
	int radius;

	// �� ��Ų
	CImage ballSkin[3];

	// ���� ��
	int SkinRnd;
public:
	Ball();

	int  BallyPos() const;

	void Draw(HDC hdc);
	void Action(void);
	void Check_Crash(HWND hWnd);
};