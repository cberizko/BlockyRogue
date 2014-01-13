#include <SFML/Graphics.hpp>
#include "GameObject.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "BlockyRogue!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
