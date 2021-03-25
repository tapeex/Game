#pragma once
#include "Object.h"
#include "Button.h"

class Pause :public Object
{
	Button exit, restart;
public:
	Pause();
	void SetPause(RenderWindow& window, float mouse_x, float mouse_y, bool pressed);
	Sprite GetSprite();

};

