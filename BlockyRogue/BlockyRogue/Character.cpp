#include "Character.hpp"
#include <iostream>

Character::Character()
{
}

void Character::initBoundingBox()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::White);
	boundingBox.setOutlineThickness(3);
	float top, bottom, left, right;
	top = bottom = shape[0].position.y;
	left = right = shape[0].position.x;
	for(int i = 1; i < shape.getVertexCount(); i++)
	{
		sf::Vector2f position = shape[i].position;
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

Character::~Character()
{
	delete velocity;
}

sf::FloatRect Character::getBounds()
{
	return sf::FloatRect(boundingBox.getPosition(), boundingBox.getSize());
}

void Character::update(float elapsed)
{
}

//Changing the enemy color becauase it was bumped
void Character::update(float elapsed, bool bump)
{
	for(int i = 0; i < shape.getVertexCount(); i++)
	{
		if (bump == false)
		{
			shape[i].color = sf::Color::Green;
		}
		else
		{
			shape[i].color = sf::Color::Blue;
		}
	}
}

void Character::draw(sf::RenderWindow* window)
{
	window->draw(boundingBox);
    window->draw(shape);
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