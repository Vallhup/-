#pragma once

#include "CHARACTER.h"
#include <time.h>
#include <atlimage.h>
#include <Windows.h>


class Alien : public Character
{
	CImage Head[2];
	CImage Body[3];

	CImage Power[2];

	int PowerRnd;

	// ????
	CImage flag;

public:
	Alien(int playerNum);

	virtual void UI_Print(HDC hdc, int playerNum) const override;
	virtual void PowerShoot(HDC hdc, int playerNum, double xpos, double ypos) override;
	virtual void Draw(HDC hdc, int playerNum) const override;
	virtual void Move(int dir, int playerNum) override;
	virtual void Jump(int dir) override;

	~Alien();
};