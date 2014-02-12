#include "PlayerProjectile.hpp"

PlayerProjectile::PlayerProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   EnemyManager *em) : Projectile(position, velocity, direction)
{
	enemyManager = em;
}

void PlayerProjectile::update(float elapsedTime)
{
	std::list<Enemy*> enemies = enemyManager->getEnemyList();

	//Only check for moving shots, not for the explosions
	if (explosion == true)
	{
		//Collision check code
		for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
		{
			if((*it)->getBounds().intersects(this->getBounds()))
			{
				//Damage enemy by one damage
				(*it)->setHealth((*it)->getHealth()-1);
				(*it)->setBump();
				dead = true;
			}
		}
	}

	//Keeps the bullet explosion on screen for some amount of frames
	if (explosion == false)
	{
		frameCount++;
		if (frameCount == 100)
		{dead=true;}
	}

	sprite.move(velocity.x * elapsedTime, velocity.y * elapsedTime);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= config["PROJECTILE_RANGE"])
		dead = true;
}