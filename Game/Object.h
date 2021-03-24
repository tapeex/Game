#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
using namespace sf;



class Object {
protected:
	float x, y;
	float dx, dy;
	short width, height;
	float speed;
	short direction;
	bool isDead;
	FloatRect boundingBox;
	bool exploding;
	float timeBetweenExplodeSlides;
	short slidesOfExploding;

	String filename;
	Texture texture;
	Sprite sprite;
public:
	bool GetIsDead() { return isDead; }
	bool GetExploding() { return exploding; }
	void Kill() { isDead = true; }
	void Explode() { exploding = true; }
};