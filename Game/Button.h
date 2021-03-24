#pragma once
#include "Object.h"

class Button: public Object
{

public:
	Button()= default;
	Button(String file)
	{
		texture.loadFromFile("images/" + file);
		sprite.setTexture(texture);
	}

	void SetButton(RenderWindow& window, float X = 0, float Y = 0)
	{
		//sprite.setScale(1.05, 1.05);
		sprite.setTextureRect(IntRect(0, 0, 220, 78));
		sprite.setPosition(X, Y);
		window.draw(sprite);
	}
	

};

