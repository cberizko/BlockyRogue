#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player():Character()
{
	velocity = new sf::Vector2f();
    
    //Creates the players dynamic shape
    initShape(config["PLAYER_SHAPE_STARTING_VERTICES"], 
              config["PLAYER_SHAPE_BASE_RADIUS"], 
              config["PLAYER_SHAPE_VARIANCE"]);

    health = config["PLAYER_MAX_HEALTH"];
    moveSpeed = config["PLAYER_MOVE_SPEED"];

	initBoundingBox();
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(boundingBox);
    window->draw(shape->getShape(sf::Color::Red));
}

Player::~Player()
{
}

void Player::update(float elapsedTime)
{
	velocity->x = 0.f;
	velocity->y = 0.f;
    sf::Vector2f moveBy;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
        moveBy += sf::Vector2f(moveSpeed*elapsedTime, 0);
		velocity->x = moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
        moveBy += sf::Vector2f(-moveSpeed*elapsedTime, 0);
		velocity->x = -moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
        moveBy += sf::Vector2f(0, -moveSpeed*elapsedTime);
		velocity->y = -moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
        moveBy += sf::Vector2f(0, moveSpeed*elapsedTime);
		velocity->y = moveSpeed;
	}
	boundingBox.setPosition(boundingBox.getPosition() + *velocity * elapsedTime);
    shape->update(moveBy);
}

sf::Vector2f Player::getPosition()
{
    return shape->points[0]->position;
}

