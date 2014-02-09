#include "Enemy.hpp"
#include <iostream>

#define PI 3.14159265

Enemy::Enemy(sf::Vector2f v2f):Character()
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("Enemy.png");
    setPosition(v2f);
    sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
   
    initShape(config["ENEMY_SHAPE_STARTING_VERTICES"], 
              config["ENEMY_SHAPE_BASE_RADIUS"], 
              config["ENEMY_SHAPE_VARIANCE"]);

    health = config["ENEMY_MAX_HEALTH"];
    moveSpeed = config["ENEMY_MOVE_SPEED"];
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

        shape[i].color = sf::Color::Green;
    }
}

void Enemy::update(float elapsed)
{
	Character::update(elapsed);
}

void Enemy::setHealth(double h)
{
    health = h;
}

double Enemy::getHealth()
{
    return health;
}