#ifndef _SCENE_HPP
#define _SCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Scene
{
	public:
		Scene(std::string name);
		virtual void update(float elapsedTime);
		virtual void draw(sf::RenderWindow* window, sf::View view);
		std::string getName();
	private:
		std::string name;
};

#endif
