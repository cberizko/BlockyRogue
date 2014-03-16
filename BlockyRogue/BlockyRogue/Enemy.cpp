#include "Enemy.hpp"
#include "EnemyManager.hpp"
#include <iostream>

#define PI 3.14159265

Enemy::Enemy(sf::Vector2f v2f, Player* p, EnemyManager* e, float range):Character()
{
	velocity = new sf::Vector2f();
	player = p;
	manager = e;
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    setPosition(v2f);

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

void Enemy::initShape(int verts, int radius, int variance)
{
    shape = sf::VertexArray(sf::TrianglesFan, verts+1);

    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        shape[i].position = sf::Vector2f((radius+radius_offset)*std::cos(location)+sprite.getPosition().x, (radius+radius_offset)*std::sin(location)+sprite.getPosition().y);

		//Uncomment to make the enemy an solid color.
		//shape[i].color = sf::Color::Green;
    }
}

void Enemy::update(float elapsed)
{
	Character::update(elapsed, bump);
	if(player->getBounds().intersects(getBounds()))
	{
		//Do Something with collision
	}
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
}