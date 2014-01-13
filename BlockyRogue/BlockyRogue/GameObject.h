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
        void setPosition(sf::Vector2f position);

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif
