#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "GameObject.hpp"
#include <iostream>
#include "getResourcePath.hpp"
#include <cmath>
#include "Character.hpp"

class Projectile: public GameObject
{
    public:
		enum Direction {LEFT, RIGHT, UP, DOWN, NONE};
		Projectile(sf::Vector2f position, sf::Vector2f velocity, Direction direction, Character *own, std::string spritePath);
		Projectile(sf::Vector2f position);
        virtual void update(float elapsedTime);
		void setVelocity(sf::Vector2f _velocity);
		bool dead;
		bool explosion;
		int frameCount;
		sf::Vector2f getPosition();
        Character* owner;
        std::string spritePath;
	protected:
    	sf::Vector2f velocity;
		sf::Vector2f origin;
};

#endif
