#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f v2f)
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout << "Enemy Created" << std::endl;
    initGraphics("Enemy.png");
    setPosition(v2f);
}

void Enemy::update()
{
}
