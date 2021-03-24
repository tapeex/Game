#include "Laser.h"

Laser::Laser(float X, float Y, short direction) : explode("ex.png", 0, 0, 50, 50, 1, 12, 20)
{
    texture.loadFromFile("images/bullets.png");
    sprite.setTextureRect(IntRect(0, 0, 50, 13));
    dx = 0; dy = 0; speed = 0; direction = 0;
    x = X;
    y = Y+35;
    isDead = false;
    if (direction < 0) this->direction = -1;
    else if (direction >= 0) this->direction = 1;
     //1 вниз, -1 верх 

	explode.GetSprite().setScale(0.5, 0.5);
	exploding = false;
	timeBetweenExplodeSlides = 0;
	slidesOfExploding = 0;
}

void Laser::SetIsDead(bool a)
{
	isDead = a;
}

Sprite Laser::GetSprite()
{
    return sprite;
}

void Laser::Update(float time, float speed, RenderWindow& window)
{
	if (!exploding) {
	sprite.setTexture(texture);
	dy = -speed * direction;
	y += dy * time;
	sprite.setPosition(x, y);
	}
	
	if (exploding && !isDead) {
		timeBetweenExplodeSlides += time;
		if (timeBetweenExplodeSlides >= 20) {
			slidesOfExploding++;
		}
		explode.Update(timeBetweenExplodeSlides, window, x, y);
		if (slidesOfExploding >= 14) isDead = true;
	}

    if (y < 0) isDead = true;
	if(y > 850) isDead = true;

	if (!exploding) {
		window.draw(sprite);
	}
}