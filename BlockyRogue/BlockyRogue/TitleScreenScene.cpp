#include "TitleScreenScene.hpp"

TitleScreenScene::TitleScreenScene(): Scene("Title Screen")
{
}

TitleScreenScene::~TitleScreenScene()
{
}

void TitleScreenScene::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        sceneHasEnded = true;
    } 
}

void TitleScreenScene::draw(sf::RenderWindow* window, sf::View view)
{   
    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
