#include "SmartPoint.hpp"

SmartPoint::SmartPoint(sf::Vector2f p, int v)
{
    position = p;
    variance = v;
    positionOffset = p;
    velocity = sf::Vector2f((std::rand()%200)-100,(std::rand()%200)-100);
}

void SmartPoint::update(sf::Vector2f moveBy)
{
    double tweenValue = .15;
    positionOffset += velocity;
    position+=moveBy;
    
    positionOffset += velocity;
    velocity = sf::Vector2f(0,0);

    //Apply recenter velocity
    positionOffset.x += (position.x - positionOffset.x)*tweenValue;
    positionOffset.y += (position.y - positionOffset.y)*tweenValue;
}
