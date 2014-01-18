#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f v2f)
{
    std::cout << "Enemy Created" << std::endl;
    initGraphics("Enemy.png");
    setPosition(v2f);
}

void Enemy::update()
{
}
