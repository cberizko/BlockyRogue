#ifndef _GAMEOVERSCREENSCENE_HPP
#define _GAMEOVERSCREENSCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "getResourcePath.hpp"

class GameOverScreenScene: Scene
{
    public:
        GameOverScreenScene();
        ~GameOverScreenScene();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window, sf::View view);

    private:
        sf::Font titleFont;
        sf::Text titleText;
        sf::Text subText;
        sf::Sprite background;
        sf::Texture backgroundTexture;
};

#endif
