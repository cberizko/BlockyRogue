#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "ConfigurationHandler.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

using namespace sf;

ConfigurationHandler config;

int main()
{

//==========================================================================
// Primary Setup
//
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopResolution, "BlockyRogue!", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(350, 300), sf::Vector2f(desktopResolution.width, desktopResolution.height));
	window.setView(view);

    SceneManager sceneManager;
    sceneManager.pushScene((Scene*)(new MainGameScene()));
   
	sf::Clock clock;

//==========================================================================
// Main Game Loop
//

    while (window.isOpen())
    {
		sf::Time elapsed = clock.restart();
        sf::Event event;

        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if(sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))
			window.close();

		p->update(elapsed.asSeconds());
        enemies->update(view);
        p->draw(&window);
        enemies->draw(&window);

		view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));
		window.setView(view);
        window.display();
        window.clear(Color(255, 255, 255, 255));
    }

    return 0;
}
