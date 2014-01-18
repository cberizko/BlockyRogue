#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    std::cout << "Enemy Created" << std::endl;
    initGraphics("Enemy.png");
    setPosition(sf::Vector2f(300.f, 100.f));
	sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);
}

void Enemy::update()
{
}
