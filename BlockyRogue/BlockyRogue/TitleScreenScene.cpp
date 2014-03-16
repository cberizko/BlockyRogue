#include "TitleScreenScene.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

TitleScreenScene::TitleScreenScene(): Scene("Title Screen")
{
    soundManager.titleMusic.stop();
    soundManager.titleMusic.play();
    soundManager.titleMusic.setPlayingOffset(sf::seconds(3.0f));
    if(!titleFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in TitleScreenScene."<< std::endl;
    }
    if(!backgroundTexture.loadFromFile(getResourcePath("Assets/Graphics/")+"TitleBackground.png"))
    {
        std::cout<<"ERROR: texture " << "TitleBackground.png" << "cannot be loaded!"<<std::endl;
    }
    else
    {
		background.setTexture(backgroundTexture);
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		background.setScale((float)desktop.width/1920.0f,(float)desktop.height/1080.0f);
        
    }
    
    titleText.setFont(titleFont);
    subText.setFont(titleFont);

    titleText.setPosition(-250,100);
    subText.setPosition(0, 300);

    titleText.setCharacterSize(160);
    subText.setCharacterSize(60);

    titleText.setString("Shape the World");
    subText.setString("Press Space to play!");
}

TitleScreenScene::~TitleScreenScene()
{
}

void TitleScreenScene::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        soundManager.titleMusic.stop();
		SceneManager::pushScene((Scene*)new MainGameScene()); 
    } 
}

void TitleScreenScene::draw(sf::RenderWindow* window, sf::View view)
{
	view.setCenter(sf::Vector2f(350, 300));
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
