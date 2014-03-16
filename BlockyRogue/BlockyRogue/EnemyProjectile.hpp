#ifndef _ENEMYPROJECTILE_HPP
#define _ENEMYPROJECTILE_HPP

#include "Projectile.hpp"
#include "Player.hpp"

class EnemyProjectile : public Projectile
{
	public:
		EnemyProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   Player *p, Character *own);
		~EnemyProjectile();
		void update(float elapsed);
	private:
		Player *player;
};

#endif