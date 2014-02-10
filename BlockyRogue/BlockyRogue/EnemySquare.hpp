#ifndef _ENEMYSQUARE_HPP
#define _ENEMYSQUARE_HPP

#include "Enemy.hpp"
#include <iostream>
#include <cmath>

class EnemySquare : public Enemy
{
public:
	EnemySquare(sf::Vector2f v2f, Player* p);
	~EnemySquare();
	void update(float elapsed);
};

#endif