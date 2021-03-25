#include "Pause.h"

Pause::Pause() :exit("Buttonexit.png"), restart("Buttonrestart.png")
{
    texture.loadFromFile("images/pause.png");
    sprite.setTexture(texture);
}

void Pause::SetPause(RenderWindow& window, float mouse_x, float mouse_y, bool pressed)
{
    window.draw(sprite);

    if (mouse_x >= 165 && mouse_x <= 380 && mouse_y >= 390 && mouse_y <= 460)  restart.SetButton(window, 165, 390, true); //200, 500); 
    else restart.SetButton(window, 165, 390); //200, 500);


    if (mouse_x >= 165 && mouse_x <= 380 && mouse_y >= 500 && mouse_y <= 570)   exit.SetButton(window, 165, 500, true); //200, 500); 
    else exit.SetButton(window, 165, 500);
}

Sprite Pause::GetSprite()
{
    return sprite;
}