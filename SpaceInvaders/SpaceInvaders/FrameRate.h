#pragma once
class FrameRate {
	static unsigned short frameRate;
	static unsigned short coldDownForLaser;
	
	static const unsigned short COLDDOWNFORLASER = 8;

	FrameRate();
public:
	static void changeFrame();
	static unsigned short getFrameRate();

	static void setColdDownForLaser();
	static unsigned short getColdDownForLaser();
};