#include "Enemy.h"

Enemy::Enemy(float X, float Y, int difficulty) : explode("ex.png", 0, 0, 50, 50, 1, 12, 15)
{
    texture.loadFromFile("images/enemies.png");
    sprite.setTextureRect(IntRect(0, 0, 100, 100));
    switch (difficulty) {
        case 1:
            sprite.setTextureRect(IntRect(0, 0, 100, 100));
            break;
        // TODO case 2,3,4,5
        default:
            sprite.setTextureRect(IntRect(0, 0, 50, 50));
            break;
    }
    sprite.setScale(0.5, 0.5);
    this->difficulty = difficulty;
    dx = 0; dy = 0; speed = 0; direction = 0;
	timeBetweenShots = 500;
	x = X;
    y = Y;
    isDead = false;
	exploding = false;
	timeBetweenExplodeSlides = 0;
	slidesOfExploding = 0;
}

float Enemy::GetTimeBetweenShots()
{
	return timeBetweenShots;
}

void Enemy::SetTimeBetweenShots(float time)
{
	timeBetweenShots = time;
}

float Enemy::GetX()
{
	return x;
}

float Enemy::GetY()
{
	return y;
}

Sprite Enemy::GetSprite()
{
	return sprite;
}

void Enemy::Update(float time, float speed, RenderWindow &window)
{
	if (!exploding) {
		timeBetweenShots += time;
		sprite.setTexture(texture);
		dy = speed;
		y += dy * time;
		sprite.setPosition(x, y);
	}

	if (y > 860) isDead = true;

	if (exploding && !isDead) {
		timeBetweenExplodeSlides += time;
		if (timeBetweenExplodeSlides >= 15) {
			slidesOfExploding++;
		}
		explode.Update(timeBetweenExplodeSlides, window, x, y);
		if (slidesOfExploding >= 13) isDead = true;
	}

	if (!exploding) {
		window.draw(sprite);
	}
}
