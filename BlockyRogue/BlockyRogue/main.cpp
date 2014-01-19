#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <iostream>
#include <list>
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
	float timeOut = 0.f;

    Player *p = new Player();
    Enemy  *e = new Enemy();
	std::list<Projectile*> projectiles;

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

		if(timeOut > 0)
			timeOut -= elapsed.asSeconds();
		else
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
					p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(300, 0)));
				timeOut = .5f;
			} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x, 
					p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-300, 0)));
				timeOut = .5f;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
					p->getPosition().y), sf::Vector2f(0, -300)));
				timeOut = .5f;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
					p->getPosition().y + p->getBounds().height), sf::Vector2f(0, 300)));
				timeOut = .5f;
			}
		}

		if(sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))
			window.close();

		for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();)
		{
			(*it)->update(elapsed.asSeconds());
			if((*it)->dead)
			{
				delete *it;
				it = projectiles.erase(it);
			}
			else
			{
				++it;
			}
		}
		p->update(elapsed.asSeconds()); 
        e->update();

		for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();++it)
		{
			(*it)->draw(&window);
		}
        p->draw(&window);
        e->draw(&window);

		view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));
		window.setView(view);
        window.display();
        window.clear(Color(0, 0, 0, 255));
    }

    return 0;
}
