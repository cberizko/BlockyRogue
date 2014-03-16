#include "SmartPoint.hpp"

SmartPoint::SmartPoint(sf::Vector2f p, int v, sf::Vector2f o)
{
    position = p;
    variance = v;
    origin = o;
    positionOffset = p;
    velocity = sf::Vector2f((std::rand()%100)-50,(std::rand()%100)-50);
}

void SmartPoint::update(sf::Vector2f moveBy)
{
    double tweenValue = .15;
    positionOffset += velocity;
    position+=moveBy;
    origin  +=moveBy;
    
    positionOffset += velocity;
    velocity = sf::Vector2f(0,0);

    //Apply recenter velocity
    positionOffset.x += (position.x - positionOffset.x)*tweenValue;
    positionOffset.y += (position.y - positionOffset.y)*tweenValue;
}
