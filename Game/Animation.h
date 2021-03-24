#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Animation
{
	Texture texture;
	Sprite sprite;
	int rectTop, rectLeft;
	int tmpRectTop, tmpRectLeft;
	int rectWidth, rectHeight;
	int rows, cols;
	float timeBetweenSlides;
	bool loop, reverseLoop;
	bool isEnded;
public:
	Animation(string filename, int rectTop, int rectLeft, int rectWidth, int rectHeight, int rows, int cols, float timeBetweenSlides, bool loop = false, bool reverseLoop = false);
	void Update(float& timeBetweenSlides, RenderWindow& window, float x, float y);
	bool GetIsEndedWithoutAnyLoop();
	void Reset();
	Sprite& GetSprite();
};

