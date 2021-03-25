#include "Menu.h"

Menu::Menu() :exit("Buttonexit.png"), play("Buttonplay.png")
{
    texture.loadFromFile("images/menu.png");
    sprite.setTexture(texture);
}

void Menu::SetMenu(RenderWindow& window, float mouse_x, float mouse_y)
{

    window.draw(sprite);

  
    if (mouse_x >= 165 && mouse_x <= 380 && mouse_y >= 390 && mouse_y <= 460)  play.SetButton(window, 165, 390, true); //200, 500); 
    else  play.SetButton(window, 165, 390);


    if (mouse_x >= 165 && mouse_x <= 380 && mouse_y >= 500 && mouse_y <= 570)   exit.SetButton(window, 165, 500, true); //200, 500); 
    else   exit.SetButton(window, 165, 500); 

    
}


Sprite Menu::GetSprite()
{
    return sprite;
}