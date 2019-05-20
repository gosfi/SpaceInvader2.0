#include "SetWindowFullScreen.h"

HANDLE SetWindowFullScreen::handle = (GetStdHandle(STD_OUTPUT_HANDLE));

SetWindowFullScreen::SetWindowFullScreen()
{}

void SetWindowFullScreen::setFullScreen()
{
	SetConsoleDisplayMode(SetWindowFullScreen::handle, CONSOLE_FULLSCREEN_MODE, 0);
}
