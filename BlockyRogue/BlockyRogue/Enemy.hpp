#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "Character.hpp"
#include "Player.hpp"
#include <cmath>
class EnemyManager;
class Enemy: public Character
{
    public:
		Enemy(sf::Vector2f v2f, Player* p, EnemyManager* e, float range);
        ~Enemy();
        void update(float elapsed);
        void draw(sf::RenderWindow* window);
        void setHealth(double health);
        double getHealth();
		bool bump;
		void setBump();
		virtual void hit() = 0;
		float aggroRange;
	protected:
		Player* player;
		EnemyManager* manager;
};

#endif
