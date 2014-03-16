#include "GameOverScreenScene.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

GameOverScreenScene::GameOverScreenScene(): Scene("Title Screen")
{
    soundManager.titleMusic.stop();
    soundManager.titleMusic.play();
    soundManager.titleMusic.setPlayingOffset(sf::seconds(3.0f));
    if(!titleFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in TitleScreenScene."<< std::endl;
    }
    if(!backgroundTexture.loadFromFile(getResourcePath("Assets/Graphics/")+"GameOverBackground.png"))
    {
        std::cout<<"ERROR: texture " << "GameOverBackground.png" << "cannot be loaded!"<<std::endl;
    }
    else
    {
		background.setTexture(backgroundTexture);
		background.setScale(.75f,.90f);
        
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
        soundManager.titleMusic.stop();
		SceneManager::popScene();
		SceneManager::pushScene((Scene*) new MainGameScene());
    } 
}

void GameOverScreenScene::draw(sf::RenderWindow* window, sf::View view)
{   
	view.setCenter(sf::Vector2f(0, 0));
	window->setView(view);
    int xStart = ((view.getCenter().x - (view.getSize().x / 2.f)));
	int yStart = ((view.getCenter().y - (view.getSize().y / 2.f)));
    background.setPosition(xStart, yStart);
    window->draw(background);
    window->draw(titleText); 
    window->draw(subText);

    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
