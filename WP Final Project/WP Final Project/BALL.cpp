#include <Windows.h>
#include <atlimage.h>
#include <random>
#include <time.h>
#include "BALL.h"

Ball::Ball()
{
	xPos = 500;
	yPos = 630;

	radius = 15;

	ballSkin[0].Load(_T("sprite\\Normal_Ball.png"));
	ballSkin[1].Load(_T("sprite\\Pink_Ball.png"));
	ballSkin[2].Load(_T("sprite\\Golden_Ball.png"));

	srand((unsigned int)time(NULL));

	SkinRnd = rand() % 3;
}

//	포물선 운동
float v_0 = INITIAL_VELOCITY;		//	던지는 힘(공의 속도)
double angle = 85.f;				//	던지는 각도
float gravity = 30.f;				//	중력
double radian = angle * PI / 180;	//	각도를 호도법으로 변환
float Time = 0.f;
double z = 0.f;						//	공이 튀어오를 값

int  Ball::BallyPos() const
{
	return yPos;
}

void Ball::Draw(HDC hdc)
{
	ballSkin[SkinRnd].TransparentBlt(hdc, xPos, yPos - z, radius * 2, radius * 2, RGB(255, 0, 0));
}


void Ball::Action()
{
	//	포물선의 식
	z = tan(radian) * Time - (gravity / (2.0 * v_0 * v_0 * cos(radian) * cos(radian))) * Time * Time;

	Time += 0.1f;
}

void Ball::Check_Crash(HWND hWnd)
{
	//	공이 착지한 경우라면
	if (yPos - z > 660)
	{
		/*	던지는 힘(속도)를 감쇠해서 다음 번에 튀어오를 때는 이전의 높이보다 낮게 튀어오르게 설정	*/
		Time = 0.f;			//	시각 초기화
		z = 0;
		yPos = START_Y_POS;	//	공의 초기 위치를 다시 설정
		v_0 *= 0.75f;		//	던지는 힘을 감쇠

		//	공의 속도가 0이면 더 이상 튀어오를 수 없으므로 속도를 0으로 설정
		if (v_0 <= 0.0001)
		{
			yPos = 630;	//	공의 초기 위치를 다시 설정
			Time = 0.f;			//	시각 초기화
			z = 0;
			v_0 = 0;			//	속도 초기화
		}
	}
}