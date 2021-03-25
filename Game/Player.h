#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Laser.h"
using namespace sf;


class Player : public Object
{ 
	int timeBetweenShots;
	short hp;
public:
	Player() = default;
	Player(String file, float x, float y, short width, short height);
	void clear();
	void SubtractHP(int damage);
	int GetHP() { return hp; }
	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();
	int GetTimeBetweenShots();
	void SpeedUpShooting();
	Sprite GetSprite();
	void Update(float time, float speed, RenderWindow &window);
	Animation explode;
};

