#include "GameObject.h"

void GameObject::FrameRateManager()
{
	FrameRate::changeFrame();
}

GameObject::GameObject()
{
	this->murTable = new Coord;
}
