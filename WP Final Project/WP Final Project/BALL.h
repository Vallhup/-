#pragma once

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

	void Draw(HDC hdc);
};