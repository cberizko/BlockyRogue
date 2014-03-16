#include "Enemy.hpp"
#include <iostream>

#define PI 3.14159265

Enemy::Enemy(sf::Vector2f v2f, Player* p, float range):Character()
{
	player = p;

    health = config["ENEMY_MAX_HEALTH"];
    moveSpeed = config["ENEMY_MOVE_SPEED"];

	bump = false;
	aggroRange = range;
}

Enemy::~Enemy()
{
}

void Enemy::update(float elapsed)
{
/*
	Character::update(elapsed, bump);

	if(player->getBounds().intersects(getBounds()))
	{
		//Do Something with collision
	}
*/
}

void Enemy::draw(sf::RenderWindow* window)
{
	window->draw(boundingBox);
    window->draw(shape->getShape(sf::Color::Green));
}

void Enemy::setHealth(double h)
{
    health = h;
}

double Enemy::getHealth()
{
    return health;
}

void Enemy::setBump()
{
	bump = true;
}
