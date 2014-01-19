#ifndef _SCENE_H
#define _SCENE_H
#include <string>
#include <SFML\Graphics.hpp>
class Scene
{
	public:
		Scene(std::string name);
		virtual void update(float elapsedTime);
		virtual void draw(sf::RenderWindow* window);
		std::string getName();
	private:
		std::string name;
};

#endif