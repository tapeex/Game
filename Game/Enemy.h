#pragma once
#include "Object.h"
class Enemy : public Object
{
	Image image;
	int difficulty;
	float timeBetweenShots;


	Animation explode;
public:
	Enemy(float X, float Y, int difficulty);

	float GetTimeBetweenShots();
	void SetTimeBetweenShots(float time);
	float GetX();
	float GetY();
	Sprite GetSprite();
	void Update(float time, float speed, RenderWindow& window);
};

