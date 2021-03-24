#include "Background.h"

Background::Background()
{
	iterator = 15;
	x = y = 0;
	texture.loadFromFile("images/spaceBack/image_part_0" + to_string(iterator) + ".jpg");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, 550, 850));
	oldPlayerX = 250;
}

void Background::Update(float time, float playerX, RenderWindow& window)
{
	bool changed = false;

	if (playerX > oldPlayerX && iterator < 30) {
		iterator++;
		changed = true;
	}
	else if (playerX < oldPlayerX && iterator > 1) {
		iterator--;
		changed = true;
	}

	oldPlayerX = playerX;

	if (changed) {
		string path = "images/spaceBack/image_part_0";
		if (iterator < 10) path += "0";
		path += to_string(iterator);
		path += ".jpg";
		texture.loadFromFile(path);
	}
	window.draw(sprite);
}

