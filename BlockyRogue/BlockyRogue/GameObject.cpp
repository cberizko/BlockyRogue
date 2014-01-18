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