#include "Player.h"
#include <iostream>

Player::Player()
{
    std::cout<<"Player Created"<<std::endl;
    if(!texture.loadFromFile("Assets/Graphics/Player.png"))
    {
        std::cout<<"ERROR: Player texture cannot be loaded!"<<std::endl;
    }
    else
    {
        sprite.setTexture(texture);
        sprite.setPosition(100.f,100.f);
    }
}

void Player::update()
{
}
