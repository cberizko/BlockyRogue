#include "Player.h"
#include <iostream>
#include "getResourcePath.h"

#define PLAYER_SPEED 200

Player::Player()
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout<<"Player Created"<<std::endl;
    if(!texture.loadFromFile(getResourcePath("Assets/Graphics/") + "Player.png"))
    {
        std::cout<<"ERROR: Player texture cannot be loaded!"<<std::endl;
    }
    else
    {
        sprite.setTexture(texture);
        sprite.setPosition(300.f,300.f);
		sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
    }
}

void Player::update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(PLAYER_SPEED * elapsedTime, 0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-PLAYER_SPEED * elapsedTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -PLAYER_SPEED * elapsedTime);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, PLAYER_SPEED * elapsedTime);
	}
}
