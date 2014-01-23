#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player()
{
	velocity = new sf::Vector2f();
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("Player.png");
    sprite.setPosition(100.f,100.f);
	sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);

    health = config["PLAYER_MAX_HEALTH"];
    moveSpeed = config["PLAYER_MOVE_SPEED"];
}

Player::~Player()
{
}

void Player::update(float elapsedTime)
{
	velocity->x = 0.f;
	velocity->y = 0.f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(moveSpeed * elapsedTime, 0);
		velocity->x = moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-moveSpeed * elapsedTime, 0);
		velocity->x = -moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -moveSpeed * elapsedTime);
		velocity->y = -moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, moveSpeed * elapsedTime);
		velocity->y = moveSpeed;
	}
}

sf::Vector2f* Player::getVelocity()
{
	return velocity;
}
