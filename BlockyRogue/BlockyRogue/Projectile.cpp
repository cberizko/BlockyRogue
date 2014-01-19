#include "Projectile.h"
#include <iostream>
#include "getResourcePath.h"
#include <cmath>

#define PLAYER_SPEED 200

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity)
{
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("Projectile.png");
    sprite.setPosition(position);
	origin = position;
	sprite.setScale(currentResolution.width / 1920.0f, currentResolution.height / 1080.0f);
	setVelocity(velocity);
	dead = false;
}

void Projectile::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void Projectile::update(float elapsedTime)
{
	sprite.move(velocity.x * elapsedTime, velocity.y * elapsedTime);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = std::sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= 600)
		dead = true;
}
