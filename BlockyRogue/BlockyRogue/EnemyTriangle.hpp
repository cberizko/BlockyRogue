#ifndef _ENEMYTRIANGLE_HPP
#define _ENEMYTRIANGLE_HPP

#include "Enemy.hpp"

class EnemyTriangle : public Enemy
{
	public:
		EnemyTriangle(sf::Vector2f v2f, Player* p, float range);
		~EnemyTriangle();
        void draw(sf::RenderWindow* window);
};

#endif
