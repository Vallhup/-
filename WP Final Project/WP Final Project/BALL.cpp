#include <Windows.h>
#include <atlimage.h>
#include <random>
#include <time.h>
#include "BALL.h"

Ball::Ball()
{
	xPos = 500;
	yPos = 300;

	radius = 15;

	ballSkin[0].Load(_T("sprite\\Normal_Ball.png"));
	ballSkin[1].Load(_T("sprite\\Pink_Ball.png"));
	ballSkin[2].Load(_T("sprite\\Golden_Ball.png"));

	srand((unsigned int)time(NULL));

	SkinRnd = rand() % 3;
}

void Ball::Draw(HDC hdc)
{
	ballSkin[SkinRnd].TransparentBlt(hdc, xPos, yPos, radius * 2, radius * 2, RGB(255, 0, 0));
}