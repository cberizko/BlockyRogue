#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player():Character()
{
	knockBackTime = .5f;
	hitDirection = new sf::Vector2f();
	velocity = new sf::Vector2f();

    //Creates the players dynamic shape
    initShape(config["PLAYER_SHAPE_STARTING_VERTICES"], 
              config["PLAYER_SHAPE_BASE_RADIUS"], 
              config["PLAYER_SHAPE_VARIANCE"]);

    //Stat Stuff
    stats["health"] = config["PLAYER_MAX_HEALTH"]; //Actually current health
    stats["moveSpeed"] = config["PLAYER_MOVE_SPEED"];
    stats["projectileDelay"] = config["PROJECTILE_DELAY"];
    stats["projectileVelocity"] = 3; //TODO: Fix projectile velocity
    stats["projectileRange"] = config["PROJECTILE_RANGE"];
    stats["projectileDamage"] = config["PROJECTILE_DAMAGE"];
    //=============
    
	Character::initBoundingBox();
}

Player::~Player()
{
	delete hitDirection;
}

void Player::hit(sf::Vector2f direction)
{
	if(knockBackTimer <= 0)
	{
		knockBackTimer = knockBackTime;
		stats["health"] -= 1;
		hitDirection->x = direction.x;
		hitDirection->y = direction.y;
	}
}

void Player::update(float elapsedTime)
{
	velocity->x = 0.f;
	velocity->y = 0.f;
	if(knockBackTimer > 0)
	{
		knockBackTimer -= elapsedTime;
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			shape[i].color = sf::Color::Blue;
			shape[i].position += *hitDirection * (float)stats["moveSpeed"] * elapsedTime;
		}
		*velocity = *hitDirection * (float)stats["moveSpeed"];
	}
	else
	{
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			shape[i].color = sf::Color::Red;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			for(int i = 0; i < shape.getVertexCount(); i++)
			{
				shape[i].position += sf::Vector2f(stats["moveSpeed"]*elapsedTime, 0);
			}
			velocity->x = stats["moveSpeed"];
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			for(int i = 0; i < shape.getVertexCount(); i++)
			{
				shape[i].position += sf::Vector2f(-stats["moveSpeed"]*elapsedTime, 0);
			}
			velocity->x = -stats["moveSpeed"];
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			for(int i = 0; i < shape.getVertexCount(); i++)
			{
				shape[i].position += sf::Vector2f(0, -stats["moveSpeed"]*elapsedTime);
			}
			velocity->y = -stats["moveSpeed"];
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			for(int i = 0; i < shape.getVertexCount(); i++)
			{
				shape[i].position += sf::Vector2f(0, stats["moveSpeed"]*elapsedTime);
			}
			velocity->y = stats["moveSpeed"];
		}
	}
	boundingBox.setPosition(boundingBox.getPosition() + *velocity * elapsedTime);
	Character::update(elapsedTime);
}

void Player::initShape(int verts, int radius, int variance)
{
    //Required Random Seed for the player shape generation
    std::srand(std::time(NULL));

    shape = sf::VertexArray(sf::TrianglesFan, verts+1);

    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        shape[i].position = sf::Vector2f((radius+radius_offset)*std::cos(location), (radius+radius_offset)*std::sin(location));

        shape[i].color = sf::Color::Red;
    }
}
