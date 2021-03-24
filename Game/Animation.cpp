#include "Animation.h"

Animation::Animation(string filename, int rectTop, int rectLeft, int rectWidth, int rectHeight, int rows, int cols, float timeBetweenSlides, bool loop, bool reverseLoop)
{
	texture.loadFromFile("images/" + filename);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(rectLeft, rectTop, rectWidth, rectHeight));

	this->rectTop = rectTop;
	this->tmpRectTop = rectTop;
	this->rectLeft = rectLeft;
	this->tmpRectLeft = rectLeft;
	this->rectWidth = rectWidth;
	this->rectHeight = rectHeight;
	this->rows = rows;
	this->cols = cols;
	this->timeBetweenSlides = timeBetweenSlides;
	this->loop = loop;
	this->reverseLoop = reverseLoop;
	isEnded = false;
}

void Animation::Update(float& timeBetweenSlides, RenderWindow & window, float x, float y) 
{ 
	if (!isEnded) {
		sprite.setPosition(x, y);
		if (timeBetweenSlides >= this->timeBetweenSlides) {
			tmpRectLeft += rectWidth;
			if (tmpRectLeft >= cols * rectWidth) {
				tmpRectLeft = rectLeft;
				tmpRectTop += rectHeight;
			}
			if (tmpRectTop >= rows * rectHeight) {
				tmpRectTop = rectTop;
				if (!loop) {
					isEnded = true;
				}
			}
			sprite.setTextureRect(IntRect(tmpRectLeft, tmpRectTop, rectWidth, rectHeight));
			timeBetweenSlides = 0;
		}
		sprite.setTexture(texture);
		window.draw(sprite);
	}
	else if (reverseLoop) {
		sprite.setPosition(x - 25, y - 25);
		if (timeBetweenSlides >= this->timeBetweenSlides) {
			tmpRectLeft -= rectWidth;
			if (tmpRectLeft <= rectWidth) {
				tmpRectLeft = rectLeft + rectWidth * (cols - 1);
				tmpRectTop -= rectHeight;
			}
			if (tmpRectTop <= rectHeight) {
				tmpRectTop = rectTop;
				isEnded = false;
			}
			sprite.setTextureRect(IntRect(tmpRectLeft, tmpRectTop, rectWidth, rectHeight));
			timeBetweenSlides = 0;
		}
		sprite.setTexture(texture);
		window.draw(sprite);
	}
}

bool Animation::GetIsEndedWithoutAnyLoop()
{
	return isEnded && !loop && !reverseLoop;
}

void Animation::Reset()
{
	isEnded = false;
	tmpRectTop = rectTop;
	tmpRectLeft = rectLeft;
}

Sprite& Animation::GetSprite()
{
	return sprite;
}
