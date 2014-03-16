#ifndef _WINSCREENSCENE_HPP
#define _WINSCREENSCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "getResourcePath.hpp"

class WinScreenScene: Scene
{
    public:
        WinScreenScene();
        ~WinScreenScene();
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
