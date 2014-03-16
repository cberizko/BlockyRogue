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
	sprite.move(velocity.x * elapsed, velocity.y * elapsed);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= owner->stats["projectileRange"])
		dead = true;
	if(getBounds().intersects(player->getBounds()))
	{
		float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
        player->stats["health"] -= owner->stats["projectileDamage"];
		player->hit(velocity / magnitude);
		dead = true;
	}
}