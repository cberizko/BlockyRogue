#ifndef _SMARTPOINT_HPP
#define _SMARTPOINT_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#define PI 3.14159265

class SmartPoint
{
    public:
        SmartPoint(sf::Vector2f p, int v);
        
        sf::Vector2f position;
        int variance;
        double radianPosition;
        sf::Vector2f positionOffset;
        sf::Vector2f velocity;

        void update(sf::Vector2f moveBy);
        void addPoint();

    private:
        
};

#endif
