#include "Pause.h"

Pause::Pause():play("Buttonplay.png"), restart("Buttonrestart.png")
{
    
    texture.loadFromFile("images/pause.png");
    sprite.setTexture(texture);
}

void Pause::SetPause(RenderWindow& window)
{

    window.draw(sprite);
    restart.SetButton(window, 150, 350); //200, 500);
    play.SetButton(window, 150, 440); //200, 500);
}

Sprite Pause::GetSprite()
{
    return sprite;
}