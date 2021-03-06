#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player():Character()
{
	knockBackTime = config["PLAYER_KNOCKBACK_TIME"];
	hitDirection = new sf::Vector2f();
	velocity = new sf::Vector2f();
    //Creates the players dynamic shape
    initShape(config["PLAYER_SHAPE_STARTING_VERTICES"], 
              config["PLAYER_SHAPE_BASE_RADIUS"], 
              config["PLAYER_SHAPE_VARIANCE"]);

	initBoundingBox();
    if(!hurtSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Player Hurt.wav"))
	{
        std::cout << "ERROR unable to load sound Player Hurt.wav in Player.cpp."<< std::endl;
    }
	if(!deadSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Player Death.wav"))
	{
        std::cout << "ERROR unable to load sound Player Death.wav in Player.cpp."<< std::endl;
    }
    //Stat Stuff
    stats["maxHealth"] = config["PLAYER_MAX_HEALTH"];
    stats["health"] = config["PLAYER_MAX_HEALTH"]; //Actually current health
    stats["moveSpeed"] = config["PLAYER_MOVE_SPEED"];
    stats["projectileDelay"] = config["PROJECTILE_DELAY"];
    stats["projectileVelocity"] = 3; //TODO: Fix projectile velocity
    stats["projectileRange"] = config["PROJECTILE_RANGE"];
    stats["projectileDamage"] = config["PROJECTILE_DAMAGE"];
}

void Player::draw(sf::RenderWindow* window)
{
	//window->draw(boundingBox);

    window->draw(shape->getShape(sf::Color(255*(stats["health"]/stats["maxHealth"]),255*(knockBackTimer/knockBackTime), 255*(knockBackTimer/knockBackTime))));
    
	Character::initBoundingBox();
}

Player::~Player()
{
	delete hitDirection;
}

void Player::hit(sf::Vector2f direction, float damage)
{
	if(knockBackTimer <= 0)
	{
        shape->bouncePoints();
		if(stats["health"] > 0)
			sound.setBuffer(hurtSound);
		else
			sound.setBuffer(deadSound);
		sound.play();
		knockBackTimer = knockBackTime;
		hitDirection->x = direction.x;
		hitDirection->y = direction.y;
		stats["health"] -= damage;
	}
}

void Player::update(float elapsedTime)
{
	velocity->x = 0.f;
	velocity->y = 0.f;
    sf::Vector2f moveBy;

	if(knockBackTimer > 0)
	{
		knockBackTimer -= elapsedTime;
        /*
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			shape[i].color = sf::Color::Blue;
    		shape[i].position += *hitDirection * (float)stats["moveSpeed"] * elapsedTime;
		}
        */
		shape->update(*hitDirection * 260.0f*elapsedTime);
	}
	else
	{
        knockBackTimer = 0;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity->x = stats["moveSpeed"];
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity->x = -stats["moveSpeed"];
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			velocity->y = -stats["moveSpeed"];
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			velocity->y = stats["moveSpeed"];
		}

        sf::Vector2f moveBy= sf::Vector2f(velocity->x*elapsedTime, velocity->y*elapsedTime);
        shape->update(moveBy);
	}
	boundingBox.setPosition(boundingBox.getPosition() + *velocity * elapsedTime);
    shape->update(moveBy);
    Character::update(elapsedTime);
}

sf::Vector2f Player::getPosition()
{
    return boundingBox.getPosition();
}

