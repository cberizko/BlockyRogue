#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include "GameObject.hpp"
#include <cmath>

class Character: public GameObject
{
    public:
        Character();
        ~Character();
        virtual void update(float elapsed);
		virtual void update(float elapsed, bool bump);
        void draw(sf::RenderWindow* window);
        sf::Vector2f getPosition();
        void setHealth(double health);
        void initShape(int verts, int radius, int variance);
        double getHealth();
		sf::Vector2f* getVelocity();
		sf::FloatRect getBounds();
		void initBoundingBox();

	protected:
		double health;
        double moveSpeed;
        sf::VertexArray shape;
		sf::Vector2f* velocity;
		sf::RectangleShape boundingBox;
};

#endif