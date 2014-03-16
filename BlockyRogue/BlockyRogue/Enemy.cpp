#include "Enemy.hpp"
#include "EnemyManager.hpp"
#include <iostream>

#define PI 3.14159265

Enemy::Enemy(sf::Vector2f v2f, Player* p, EnemyManager* e, float range):Character()
{
	velocity = new sf::Vector2f();
	player = p;
	manager = e;
    setPosition(v2f);

    stats["maxHealth"] = config["ENEMY_MAX_HEALTH"];
    stats["health"] = config["ENEMY_MAX_HEALTH"];
    stats["moveSpeed"] = config["ENEMY_MOVE_SPEED"];
    stats["projectileDelay"] = config["ENEMY_PROJECTILE_DELAY"];
    stats["projectileVelocity"] = 3; //TODO: Fix projectile velocity
    stats["projectileRange"] = config["ENEMY_PROJECTILE_RANGE"];
    stats["projectileDamage"] = config["ENEMY_PROJECTILE_DAMAGE"];

	bump = false;
	aggroRange = range;
}

Enemy::~Enemy()
{
}

void Enemy::update(float elapsed)
{
    
    Character::update(elapsed);
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
    window->draw(shape->getShape(sf::Color(0,255*(stats["health"]/stats["maxHealth"]),0)));
}

void Enemy::setHealth(double h)
{
    stats["health"] = h;
}

double Enemy::getHealth()
{
    return stats["health"];
}

void Enemy::setBump()
{
	bump = true;
    shape->bouncePoints();
}
