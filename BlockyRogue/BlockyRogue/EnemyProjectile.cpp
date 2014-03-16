#include "EnemyProjectile.hpp"

EnemyProjectile::EnemyProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   Player *p, Character *own) : Projectile(position, velocity, direction, own)
{
	player = p;
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::update(float elapsed)
{
	if(getBounds().intersects(player->getBounds()))
	{
		//Do something with collision
	}
}