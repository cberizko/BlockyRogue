#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
    std::cout << "Enemy Created" << std::endl;
    initGraphics("Assets/Graphics/Enemy.png");
    setPosition(sf::Vector2f(300.f, 100.f));
}

void Enemy::update()
{
}
