#pragma once
#include "Object.h"
#include "Button.h"

class Pause :public Object
{
	Button play, exit, restart;
	
public:
	Pause();
	void SetPause(RenderWindow& window);
	Sprite GetSprite();
	
};

