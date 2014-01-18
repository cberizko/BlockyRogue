#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

using namespace sf;

int main()
{
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopResolution, "BlockyRogue!", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(350, 300), sf::Vector2f(desktopResolution.width, desktopResolution.height));
	window.setView(view);
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

		view.setCenter(p->getPosition());
		window.setView(view);
        window.display();
        window.clear();
    }

    return 0;
}
