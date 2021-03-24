#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Background
{
	String filename;
	Texture texture;
	Sprite sprite;
	float x, y;
	short iterator;
	float oldPlayerX;

public:
	Background();

	void Update(float time, float playerX, RenderWindow& window);
};

