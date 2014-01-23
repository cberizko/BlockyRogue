#include "Projectile.hpp"
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

void Projectile::update(float elapsedTime, EnemyManager* enemyManager)
{
    //TODO: Add collision check code for enemies.
    std::list<Enemy*> enemies = enemyManager->getEnemyList();

    //Collision check code
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        if((*it)->getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds()))
        {
            //Damage enemy by one damage
            (*it)->setHealth((*it)->getHealth()-1);            
            dead = true;
        }
    }

	sprite.move(velocity.x * elapsedTime, velocity.y * elapsedTime);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= 600)
		dead = true;
}
