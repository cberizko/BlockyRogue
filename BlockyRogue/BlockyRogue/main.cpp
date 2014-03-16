#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "ConfigurationHandler.hpp"
#include "SoundManager.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"
#include "TitleScreenScene.hpp"

using namespace sf;

ConfigurationHandler config;
SoundManager soundManager;

int main()
{

//==========================================================================
// Primary Setup
//
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window; 

    if(config["FULLSCREEN_MODE"] == 1)
    {
         window.create(desktopResolution, "Shape The World!", sf::Style::Fullscreen);
    }
    else
    {
         window.create(desktopResolution, "Shape The World!");
    }

	sf::View view(sf::Vector2f(350, 300), sf::Vector2f(desktopResolution.width, desktopResolution.height));
	window.setView(view);
    SceneManager sceneManager;
    sceneManager.pushScene((Scene*)(new TitleScreenScene()));

	sf::Clock clock;

//==========================================================================
// Main Game Loop
//
    while (window.isOpen())
    {
		sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					SceneManager::popScene();
				}
			}
        }
        
        sceneManager.update(elapsed.asSeconds());
        sceneManager.draw(&window, view);
    }

    window.close();

    return 0;
}
