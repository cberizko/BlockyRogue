#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f v2f)
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout << "Enemy Created" << std::endl;
    initGraphics("Enemy.png");
    setPosition(v2f);
    sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
}

void Enemy::update(float elapsed)
{
}
