#include "CHARACTER.h"

extern RECT WinSize;
extern BOOL CrashCheck;

Character::Character()
{
	xPos = 0;
	yPos = 0;
	powerGauge = 0;
}

RECT Character::CharPos()
{
	RECT CharPos = { xPos, yPos, xPos + CHAR_SIZE, yPos + CHAR_SIZE + 7 };
	return CharPos;
}