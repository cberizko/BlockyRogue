#ifndef _PLAYERPROJECTILE_HPP
#define _PLAYERPROJECTILE_HPP

#include "Projectile.hpp"
#include "EnemyManager.hpp"

class PlayerProjectile : public Projectile
{
	public:
		PlayerProjectile(sf::Vector2f position, sf::Vector2f velocity, Projectile::Direction direction, EnemyManager *enemyManager);
		PlayerProjectile(sf::Vector2f position, EnemyManager *enemyManager);
		~PlayerProjectile();
		void update(float elapsed);
	private:
		EnemyManager *enemyManager;
};

#endif