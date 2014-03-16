#include "WinScreenScene.hpp"
#include "SceneManager.hpp"
#include "MainGameScene.hpp"

WinScreenScene::WinScreenScene(): Scene("Win Screen")
{
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
		background.setScale(.75f,.90f);
        
    }
    
    titleText.setFont(titleFont);
    subText.setFont(titleFont);

    titleText.setCharacterSize(160);
    subText.setCharacterSize(60);

    titleText.setString("YOU WIN!");
    subText.setString("");

	titleText.setPosition(-titleText.getGlobalBounds().width / 2.f,-200);
	subText.setPosition(-subText.getGlobalBounds().width / 2.f,0);
}

WinScreenScene::~WinScreenScene()
{
}

void WinScreenScene::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
		SceneManager::popScene();
		SceneManager::pushScene((Scene*) new MainGameScene());
    } 
}

void WinScreenScene::draw(sf::RenderWindow* window, sf::View view)
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
