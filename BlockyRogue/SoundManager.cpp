#include "SoundManager.hpp"

SoundManager::SoundManager()
{
    if(!music.openFromFile(getResourcePath("Assets/Sounds/") + "Trance - Candy Dance.wav"))
	{
		std::cout << "ERROR unable to load music Trance - Candy Dance.wav in MainGameScene.cpp." << std::endl;
	}
	if(!playerShootSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Player shoot.wav"))
	{
        std::cout << "ERROR unable to load sound Player shoot.wav in MainGameScene.cpp."<< std::endl;
    }
    if(!upgradeSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Upgrade.wav"))
	{
        std::cout << "ERROR unable to load sound Upgrade.wav in MainGameScene.cpp."<< std::endl;
    }
    if(!squareHurtSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Enemy Square hurt.wav"))
	{
        std::cout << "ERROR unable to load sound Enemy Square hurt.mp3 in EnemySquare.cpp."<< std::endl;
    }
    if(!triangleHurtSound.loadFromFile(getResourcePath("Assets/Sounds/")+"EnemyTriangle hurt.wav"))
	{
        std::cout << "ERROR unable to load sound EnemyTriangle hurt.mp3 in EnemyTriangle.wav."<< std::endl;
    }
    if(!playerHurtSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Player Hurt.wav"))
	{
        std::cout << "ERROR unable to load sound Player Hurt.wav in Player.cpp."<< std::endl;
    }
	if(!playerDeadSound.loadFromFile(getResourcePath("Assets/Sounds/")+"Player Death.wav"))
	{
        std::cout << "ERROR unable to load sound Player Death.wav in Player.cpp."<< std::endl;
    }

}

sf::SoundBuffer* SoundManager::getSoundBuffer(std::string name)
{
    if(!name.compare("playerShoot"))
        return &playerShootSound;
    if(!name.compare("upgrade"))
        return &upgradeSound;
    if(!name.compare("squareHurt"))
        return &squareHurtSound;
    if(!name.compare("triangleHurt"))
        return &triangleHurtSound;
    if(!name.compare("playerHurt"))
        return &playerHurtSound;
    if(!name.compare("playerDead"))
        return &playerDeadSound;
    
    
    //Return default shoot sound if fail
    return &playerShootSound;
}