#ifndef _TITLESCREENSCENE_HPP
#define _TITLESCREENSCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>

class TitleScreenScene: Scene
{
    public:
        TitleScreenScene();
        ~TitleScreenScene();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window, sf::View view);

    private:
        
};

#endif
