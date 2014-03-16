#ifndef _PLAYER_H
#define _PLAYER_H
#include "Character.hpp"
#include "SmartShape.hpp"
#include <cmath>
#include <SFML/Audio.hpp>


class Player: public Character
{
    public:
        Player();
        ~Player();
        void update(float elapsedTime);
        void draw(sf::RenderWindow *window);
        sf::Vector2f getPosition();
		void hit(sf::Vector2f direction, float damage);
	protected:
		sf::Vector2f* hitDirection;
		float knockBackTime;
		float knockBackTimer;
		sf::Sound sound;
};

#endif
