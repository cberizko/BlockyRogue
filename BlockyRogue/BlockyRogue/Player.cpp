#include "Player.h"
#include <iostream>

Player::Player()
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout<<"Player Created"<<std::endl;
    if(!texture.loadFromFile("Assets/Graphics/Player.png"))
    {
        std::cout<<"ERROR: Player texture cannot be loaded!"<<std::endl;
    }
    else
    {
        sprite.setTexture(texture);
        sprite.setPosition(100.f,100.f);
		sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
    }
}

void Player::update(float elapsedTime)
{
	sf::Vector2f size = sprite.getScale();
	std::cout << size.x << " " << size.y << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(30 * elapsedTime, 0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-30 * elapsedTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -30 * elapsedTime);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, 30 * elapsedTime);
	}
}
