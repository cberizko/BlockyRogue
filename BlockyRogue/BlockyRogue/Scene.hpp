#ifndef _SCENE_HPP
#define _SCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Scene
{
	public:
		Scene(std::string name);
        virtual ~Scene();
		virtual void update(float elapsedTime) = 0;
		virtual void draw(sf::RenderWindow* window, sf::View view) = 0; 
		std::string getName();
        bool hasEnded();

	private:
		std::string name;
        
    protected:
        bool sceneHasEnded;
};

#endif
