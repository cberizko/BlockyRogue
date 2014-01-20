#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player()
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout<<"Player Created"<<std::endl;
    initGraphics("Player.png");
    sprite.setPosition(100.f,100.f);
	sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
}

void Player::update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(PLAYER_MOVE_SPEED * elapsedTime, 0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-PLAYER_MOVE_SPEED * elapsedTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -PLAYER_MOVE_SPEED * elapsedTime);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, PLAYER_MOVE_SPEED * elapsedTime);
	}
}
