#include "Character.hpp"
#include <iostream>

Character::Character()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::White);
	boundingBox.setOutlineThickness(3);
}

Character::~Character()
{
}

sf::FloatRect Character::getBounds()
{
	return sf::FloatRect(boundingBox.getPosition(), boundingBox.getSize());
}

void Character::update(float elapsed)
{
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