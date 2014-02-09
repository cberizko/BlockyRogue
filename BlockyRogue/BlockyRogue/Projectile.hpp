#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "GameObject.hpp"
#include "EnemyManager.hpp"
#include <iostream>
#include "getResourcePath.hpp"
#include <cmath>
#include "Enemy.hpp"

class Projectile: public GameObject
{
    public:
		enum Direction {LEFT, RIGHT, UP, DOWN};
		Projectile(sf::Vector2f position, sf::Vector2f velocity, Direction direction);
		Projectile(sf::Vector2f position);
        void update(float elapsedTime, EnemyManager* EnemyManager);
		void setVelocity(sf::Vector2f _velocity);
		bool dead;
		bool explosion;
		int frameCount;
		sf::Vector2f getPosition();
	protected:
    	sf::Vector2f velocity;
		sf::Vector2f origin;
};

#endif
