#pragma once
#include "Object.h"
#include "Button.h"

class Menu: public Object
{
	Button play, exit;
public:
	Menu();
	void SetMenu(RenderWindow& window, float mouse_x, float mouse_y);
	Sprite GetSprite();

};

