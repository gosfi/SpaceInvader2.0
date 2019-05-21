#include "FrameRate.h"

unsigned short FrameRate::frameRate = 0;
unsigned short FrameRate::coldDownForLaser = 2;
FrameRate::FrameRate(){}

void FrameRate::changeFrame()
{
	if (FrameRate::frameRate < 400)
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
