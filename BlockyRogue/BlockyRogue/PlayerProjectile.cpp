#include "PlayerProjectile.hpp"

PlayerProjectile::PlayerProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   EnemyManager *em, Character *owner) : Projectile(position, velocity, direction, owner)
{
	enemyManager = em;
}

void PlayerProjectile::update(float elapsedTime)
{
	std::list<Enemy*>* enemies = enemyManager->getEnemyList();

	//Only check for moving shots, not for the explosions
	//Collision check code
	for (std::list<Enemy*>::iterator it = enemies->begin(); it != enemies->end();++it)
	{
		if((*it)->getBounds().intersects(this->getBounds()))
		{
			if((*it)->getBounds().intersects(this->getBounds()))
			{
				//Damage enemy by one damage
				(*it)->setHealth((*it)->getHealth()-(owner->getStats()["projectileDamage"]));
				(*it)->setBump();
				(*it)->hit();
				dead = true;
			}
		}
	}

	sprite.move(velocity.x * elapsedTime, velocity.y * elapsedTime);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= owner->getStats()["projectileRange"])
		dead = true;
}
