#pragma once
#include <Windows.h>
class SetWindowFullScreen {
	//setFullScreen
	static HANDLE handle;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	COORD buffer;

	SetWindowFullScreen();
public:
	static void setFullScreen();
};