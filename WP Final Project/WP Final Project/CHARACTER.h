#pragma once

class Character {
	// 이름
	//std::string name;

	// 능력치
	int jump;
	int speed;
	int power;

	// 좌표
	int xPos;
	int yPos;

	// 깃발
	CImage flag;

	// 파워게이지
	int powerGauge;

	// 점수
	int score;

public:
	Character(int jump, int speed, int power, int xPos, int yPos);

	void UI_Print(HDC hdc, int x, int y);
};