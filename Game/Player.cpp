#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Player::Player(String file, float X, float Y, short W, short H) : explode("ex.png", 0, 0, 50, 50, 1, 12, 30)
{
    //sprite.setColor(sf::Color(255, 255, 255, 128));//устанавливаем цвет(RGB) и прозрачность
    dx = 0; dy = 0; speed = 0; direction = 0;
    width = W;
    height = H;
    x = X;
    y = Y;
    filename = file;
	timeBetweenShots = 300;
	hp = 100;
	isDead = false;
    
    texture.loadFromFile("images/" + file);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, width, height));
    //sprite.setScale(0.2, 0.2);


	exploding = false;
	timeBetweenExplodeSlides = 0;
	slidesOfExploding = 0;
}

void Player::SubtractHP(int damage)
{
	hp -= damage;
}

float Player::GetX()
{
	return x;
}

float Player::GetY()
{
	return y;
}

int Player::GetWidth()
{
	return width;
}

int Player::GetHeight()
{
	return height;
}

int Player::GetTimeBetweenShots()
{
	return timeBetweenShots;
}

Sprite Player::GetSprite()
{
    return sprite;
}

void Player::Update(float time, float speed, RenderWindow& window)
{
	if (hp <= 0) exploding = true;
	
	if (!exploding) {
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) { dx = -speed; }
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) { dx = speed; }
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) { dy = -speed; }
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) { dy = speed / 2; }
		x += dx * time;
		y += dy * time;


		if (x + width > 555) x = 555 - width;
		else if (x < 5) x = 5;
		if (y + height + 10 > 720) y = 720 - height - 10;
		else if (y < 5) y = 5;
		dx = dy = 0;
		sprite.setPosition(x, y);
		window.draw(sprite);
	}

	if (exploding && !isDead) {
		timeBetweenExplodeSlides += time;
		if (timeBetweenExplodeSlides >= 30) {
			slidesOfExploding++;
		}
		explode.Update(timeBetweenExplodeSlides, window, x, y);
		if (slidesOfExploding >= 13) isDead = true;
	}
}
