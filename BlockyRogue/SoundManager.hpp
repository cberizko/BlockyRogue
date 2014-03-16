#ifndef __BlockyRogue__SoundManager__
#define __BlockyRogue__SoundManager__

#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include "getResourcePath.hpp"

class SoundManager
{
public:
    SoundManager();
    
    sf::SoundBuffer* getSoundBuffer(std::string name);
    
    sf::SoundBuffer playerShootSound;
    sf::SoundBuffer upgradeSound;
    sf::SoundBuffer squareHurtSound;
    sf::SoundBuffer triangleHurtSound;
    sf::SoundBuffer playerHurtSound;
    sf::SoundBuffer playerDeadSound;
    sf::SoundBuffer enemyShootSound;
    sf::Music music;

protected:

    
};

#endif
