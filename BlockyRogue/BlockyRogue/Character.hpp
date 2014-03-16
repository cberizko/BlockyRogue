#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include "GameObject.hpp"
#include "SmartShape.hpp"
#include "Upgrade.hpp"
#include <cmath>
#include <string>

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
        void initShape(int verts, int radius, int variance, sf::Vector2f p);
        double getHealth();
		sf::Vector2f* getVelocity();
		sf::FloatRect getBounds();
		void initBoundingBox();
        void applyUpgrade(Upgrade upgrade);
		std::map<std::string, double> stats;
        std::map<std::string, double> getStats();

	protected:
        SmartShape* shape;
		sf::Vector2f* velocity;
		sf::RectangleShape boundingBox;
};

#endif
