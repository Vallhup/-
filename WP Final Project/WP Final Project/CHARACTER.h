#pragma once

class Character {
	// �̸�
	//std::string name;

	// �ɷ�ġ
	int jump;
	int speed;
	int power;

	// ��ǥ
	int xPos;
	int yPos;

	// ���
	CImage flag;

	// �Ŀ�������
	int powerGauge;

	// ����
	int score;

public:
	Character(int jump, int speed, int power, int xPos, int yPos);

	void UI_Print(HDC hdc, int x, int y);
};