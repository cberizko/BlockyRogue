#include "GameObject.h"
#include <iostream>

//Basic Constructor
GameObject::GameObject()
{
}

//Called once per clock cycle.
void GameObject::update()
{
}

//Draws sprite to the screen.
void GameObject::draw(sf::RenderWindow*  window)
{
    window->draw(sprite);
}

//Gets the position data from the sprite
sf::Vector2f GameObject::getPosition()
{
    return sprite.getPosition();
}

//Sets position data in the sprite
void GameObject::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

//Gets the scale data from the sprite
sf::Vector2f GameObject::getScale()
{
	return sprite.getScale();
}

//Sets the scale of the sprite
void GameObject::setScale(sf::Vector2f scale)
{
	sprite.setScale(scale);
}

//Gets the pixel dimensions of the object
sf::Vector2f GameObject::getDimensions()
{
	const sf::Texture * texture = sprite.getTexture();
	return sf::Vector2f(texture->getSize().x * sprite.getScale().x, texture->getSize().y * sprite.getScale().y);
}