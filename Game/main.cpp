#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameEngine.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(550, 850), "Game", Style::Close); // 550 850
	//Player player("HeroSprite.png", 250, 500, 50, 50);
	Player player("HeroSptait.png", 250, 500, 50, 50);
	GameEngine gameEngine(window, player);

    //std::vector<int> v;
    //std::cout << "Default-constructd capacity is " << v.size() << '\n';
    //v.resize(100);
    //std::cout << "Capacity of a 100-element vector is " << v.size() << '\n';
    //v.clear();
    //std::cout << "Capacity after clear() is " << v.size() << '\n';
    //v.shrink_to_fit();
    //std::cout << "Capacity after shrink_to_fit() is " << v.size() << '\n';

	return 0;
}