#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "BlockyRogue!", sf::Style::Fullscreen);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    sf::Texture t;

    Player *p = new Player();
	sf::Clock clock;
	window.setMouseCursorVisible(false);
    while (window.isOpen())
    {
		sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		p->update(elapsed.asSeconds()); 
        p->draw(&window);
        window.display();
        window.clear();
    }

    return 0;
}
