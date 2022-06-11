#include "CHARACTER.h"

extern RECT WinSize;
extern BOOL CrashCheck;

Character::Character()
{
	xPos = 0;
	yPos = 0;
	PwGauge = 0;

	PowerGaugeL.Load(_T("PowerGauge_L.png"));
	PowerGaugeFrameL.Load(_T("PowerGaugeFrame_L.png"));

	PowerGaugeR.Load(_T("PowerGauge_R.png"));
	PowerGaugeFrameR.Load(_T("PowerGaugeFrame_R.png"));
}

RECT Character::CharPos()
{
	RECT CharPos = { xPos, yPos, xPos + CHAR_SIZE, yPos + CHAR_SIZE + 7 };
	return CharPos;
}

void Character::PwGaugeFull()
{
	PwGauge += power;

	if (PwGauge >= 100) {
		PwGauge = 100;
	}
}