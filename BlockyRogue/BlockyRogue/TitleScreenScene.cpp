#include "TitleScreenScene.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

TitleScreenScene::TitleScreenScene(): Scene("Title Screen")
{
    if(!titleFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in TitleScreenScene."<< std::endl;
    }
	std::cout << "LOADED TITLE SCREEN";
    titleText.setFont(titleFont);
    subText.setFont(titleFont);

    titleText.setPosition(-150,100);
    subText.setPosition(0, 300);

    titleText.setCharacterSize(160);
    subText.setCharacterSize(60);

    titleText.setString("Blocky Rogue");
    subText.setString("Press Space to play!");
}

TitleScreenScene::~TitleScreenScene()
{
}

void TitleScreenScene::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
		SceneManager::pushScene((Scene*)new MainGameScene()); 
    } 
}

void TitleScreenScene::draw(sf::RenderWindow* window, sf::View view)
{   
	view.setCenter(sf::Vector2f(350, 300));
	window->setView(view);
    window->draw(titleText); 
    window->draw(subText);

    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
