#ifndef _PLAYER_H
#define _PLAYER_H
#include "GameObject.hpp"
#include <cmath>

#define PI 3.14159265

class Player: public GameObject
{
    public:
        Player();
        ~Player();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window);
        void initShape(int verts, int radius, int variance);
		sf::Vector2f* getVelocity();

	private:
		double health;
        double moveSpeed;
		sf::Vector2f* velocity;
        sf::VertexArray shape;
};

#endif
