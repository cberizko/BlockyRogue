#include "Projectile.hpp"
#define PLAYER_SPEED 200

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity, Projectile::Direction direction)
{
	sf::Vector2f offset;
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("Projectile.png");
	sprite.setScale(currentResolution.width / 1920.0f, currentResolution.height / 1080.0f);

	//Set offset of the projectile based on which side of the player it's spawning on
	switch(direction)
	{
	case Projectile::LEFT:
		offset = sf::Vector2f(-getBounds().width, -getBounds().height / 2);
		break;
	case Projectile::RIGHT:
		offset = sf::Vector2f(0, -getBounds().height / 2);
		break;
	case Projectile::UP:
		offset = sf::Vector2f(-getBounds().width / 2, -getBounds().height);
		break;
	case Projectile::DOWN:
		offset = sf::Vector2f(-getBounds().width / 2, 0);
	};
	sprite.setPosition(position + offset);
	origin = position;

	setVelocity(velocity);
	dead = false;
}

void Projectile::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void Projectile::update(float elapsedTime, EnemyManager* enemyManager)
{
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
