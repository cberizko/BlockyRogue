#include "GameOverScreenScene.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

GameOverScreenScene::GameOverScreenScene(): Scene("Title Screen")
{
    if(!titleFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in TitleScreenScene."<< std::endl;
    }
    
    titleText.setFont(titleFont);
    subText.setFont(titleFont);

    titleText.setCharacterSize(160);
    subText.setCharacterSize(60);

    titleText.setString("Game Over");
    subText.setString("Press Space to Retry!");

	titleText.setPosition(-titleText.getGlobalBounds().width / 2.f,-200);
	subText.setPosition(-subText.getGlobalBounds().width / 2.f,0);
}

GameOverScreenScene::~GameOverScreenScene()
{
}

void GameOverScreenScene::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
		SceneManager::popScene();
		SceneManager::pushScene((Scene*) new MainGameScene());
    } 
}

void GameOverScreenScene::draw(sf::RenderWindow* window, sf::View view)
{   
	view.setCenter(sf::Vector2f(0, 0));
	window->setView(view);
    window->draw(titleText); 
    window->draw(subText);

    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
