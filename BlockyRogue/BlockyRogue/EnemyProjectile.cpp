#include "EnemyProjectile.hpp"

EnemyProjectile::EnemyProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   Player *p) : Projectile(position, velocity, direction)
{
	player = p;
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::update(float elapsed)
{
	sprite.move(velocity.x * elapsed, velocity.y * elapsed);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= config["PROJECTILE_RANGE"])
		dead = true;
	if(getBounds().intersects(player->getBounds()))
	{
		//Do something with collision
	}
}