#include "FrameRate.h"

unsigned short FrameRate::frameRate = 0;
unsigned short FrameRate::coldDownForLaser = 5;
FrameRate::FrameRate(){}

void FrameRate::changeFrame()
{
	if (FrameRate::frameRate < 10)
	{
		FrameRate::frameRate++;
	}
	else
	{
		FrameRate::frameRate = 0;
	}
	if (FrameRate::coldDownForLaser != 0)
	{
		FrameRate::coldDownForLaser--;
	}
}

unsigned short FrameRate::getFrameRate()
{
	return FrameRate::frameRate;
}


void FrameRate::setColdDownForLaser()
{
	FrameRate::coldDownForLaser = FrameRate::COLDDOWNFORLASER;
}

unsigned short FrameRate::getColdDownForLaser()
{
	return FrameRate::coldDownForLaser;
}
