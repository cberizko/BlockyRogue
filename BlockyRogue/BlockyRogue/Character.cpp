#include "Character.hpp"
#include <iostream>

Character::Character()
{
}

Character::~Character()
{
    delete shape;
    delete velocity;
}

void Character::initShape(int verts, int radius, int variance)
{
   shape = new SmartShape(verts, radius, variance); 
}


void Character::initShape(int verts, int radius, int variance, sf::Vector2f p)
{
   shape = new SmartShape(verts, radius, variance, p); 
}

void Character::initBoundingBox()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::White);
	boundingBox.setOutlineThickness(3);
	float top, bottom, left, right;
	top = bottom = shape->points[0]->position.y;
	left = right = shape->points[0]->position.x;
	for(int i = 1; i < shape->points.size(); i++)
	{
		sf::Vector2f position = shape->points[i]->position;
		if(position.x > right)
			right = position.x;
		else if(position.x < left)
			left = position.x;
		if(position.y < top)
			top = position.y;
		else if(position.y > bottom)
			bottom = position.y;
	}
	boundingBox.setPosition(sf::Vector2f(left, top));
	boundingBox.setSize(sf::Vector2f(right - left, bottom - top));
}

std::map<std::string, double> Character::getStats()
{
    return stats;
}

sf::FloatRect Character::getBounds()
{
	return sf::FloatRect(boundingBox.getPosition(), boundingBox.getSize());
}

void Character::update(float elapsed)
{
    if(stats["maxHealth"] <= stats["health"])
        stats["health"] = stats["maxHealth"];
}

//Changing the enemy color becauase it was bumped
void Character::update(float elapsed, bool bump)
{
    update(elapsed);
    //TODO: Bump Color Change Here
}

void Character::draw(sf::RenderWindow* window)
{
	window->draw(boundingBox);
    window->draw(shape->getShape(sf::Color::Red));
}

sf::Vector2f Character::getPosition()
{
	return boundingBox.getPosition();
}

sf::Vector2f* Character::getVelocity()
{
	return velocity;
}

void Character::applyUpgrade(Upgrade upgrade)
{
    if(upgrade.getMod().compare("+") == 0)
        stats[upgrade.getType()] += upgrade.getAmount();
    if(upgrade.getMod().compare("*") == 0)
        stats[upgrade.getType()] *= upgrade.getAmount();
    if(upgrade.getMod().compare("=") == 0)
        stats[upgrade.getType()] = upgrade.getAmount();
    
    if(stats[upgrade.getType()] <= 0)
        stats[upgrade.getType()] = 0.0001;
}
