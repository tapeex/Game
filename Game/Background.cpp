#include "Background.h"

Background::Background()
{
	iterator = 30;
	timeBetweenSlides = 0;
	x = y = 0;
	texture.loadFromFile("images/back/image_part_" + to_string(iterator) + ".jpg");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, 550, 850));
}

void Background::Update(float time, float speed, RenderWindow& window)
{
	timeBetweenSlides += time;
	if (timeBetweenSlides >= 5) {
		string path = "images/back/image_part_0";
		iterator--;
		if (iterator < 1) iterator = 31;
		if (iterator < 10) path += "0";
		path += to_string(iterator);
		path += ".jpg";
		texture.loadFromFile(path);
		timeBetweenSlides = 0;
	}
	sprite.setTexture(texture);

	window.draw(sprite);
}
