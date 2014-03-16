#ifndef _ENEMYTRIANGLE_HPP
#define _ENEMYTRIANGLE_HPP

#include "Enemy.hpp"
#include "EnemyProjectile.hpp"
#include <list>
class EnemyManager;
class EnemyTriangle : public Enemy
{
	public:
		EnemyTriangle(sf::Vector2f v2f, Player* p, EnemyManager* e, float range, std::list<Projectile*> *proj);
		~EnemyTriangle();
		void update(float elapsed);
        void draw(sf::RenderWindow* window);
	protected:
		float coolDownTimer;
		float coolDownTime;
		std::list<Projectile*> *projectiles;
};

#endif
