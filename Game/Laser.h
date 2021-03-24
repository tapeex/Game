#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
using namespace sf;
class Laser : public Object
{

public:
	Laser(float x, float y, short direction);

	void SetIsDead(bool a);
	Sprite GetSprite();
    void Update(float time, float speed, RenderWindow &window);

	Animation explode;
};

