#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "GameObject.hpp"

class Enemy: public GameObject
{
    public:
        Enemy(sf::Vector2f v2f);
        void update(float elapsed);
	private:
		double health;
        double moveSpeed;
};

#endif
