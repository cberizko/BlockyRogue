#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
    public:
        GameObject();

        virtual void update();
        //SFML's sprite class can handle position and boundingbox collision!
        sf::Vector2f getPosition();
		sf::Vector2f getScale();
		sf::Vector2f getDimensions();
		void setScale(sf::Vector2f scale);
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderWindow* window);
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif
