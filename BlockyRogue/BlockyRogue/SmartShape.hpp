#ifndef _SMARTSHAPE_HPP
#define _SMARTSHAPE_HPP
#include <SFML/Graphics.hpp>
#include "SmartPoint.hpp"
#include <iostream>
#include <list>

class SmartShape
{
    public:
        SmartShape(int verts, int radius, int variance);
        SmartShape(int verts, int radius, int variance, sf::Vector2f p);

        void update(sf::Vector2f moveBy);
        sf::VertexArray getShape(sf::Color c);

        std::vector<SmartPoint*> points;
        void bouncePoints();

    private:
        sf::VertexArray vertArray;
};

#endif
