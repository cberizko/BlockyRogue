#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "GameObject.h"

class Projectile: public GameObject
{
    public:
        Projectile(sf::Vector2f position, sf::Vector2f velocity);
        void update(float elapsedTime);
		void setVelocity(sf::Vector2f _velocity);
		bool dead;
	protected:
		sf::Vector2f velocity;
		sf::Vector2f origin;
};

#endif