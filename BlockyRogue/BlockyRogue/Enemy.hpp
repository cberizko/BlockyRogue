#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "GameObject.hpp"
#include <cmath>

class Enemy: public GameObject
{
    public:
        Enemy(sf::Vector2f v2f);
        ~Enemy();
        void update(float elapsed);
        void draw(sf::RenderWindow* window);
        sf::Vector2f getPosition();
        void setHealth(double health);
        void initShape(int verts, int radius, int variance);
        double getHealth();

	private:
		double health;
        double moveSpeed;
        sf::VertexArray shape;
};

#endif
