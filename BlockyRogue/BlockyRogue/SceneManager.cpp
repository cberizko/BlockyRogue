#include "SceneManager.hpp"
Scene* SceneManager::currentScene;
std::list<Scene*> SceneManager::scenes;

void SceneManager::pushScene(Scene* scene)
{
	scenes.push_back(scene);
	currentScene = scene;
}

void SceneManager::popScene()
{
	if(scenes.size() <= 0)
		return;
	Scene *removed = scenes.back();
	scenes.pop_back();
	delete removed;
	currentScene = scenes.back();
    //TODO: Shouldn't there be clean up for the removed scene?
}

void SceneManager::removeScene(Scene* scene)
{
	for (std::list<Scene*>::iterator it = scenes.begin(); it != scenes.end();)
	{
		if((*it)->getName().compare(scene->getName()) == 0)
		{
			delete *it;
			it = scenes.erase(it);
		}
		else
		{
			++it;
		}
	}
	currentScene = scenes.back();
}

void SceneManager::draw(sf::RenderWindow* window, sf::View view)
{
	currentScene->draw(window, view);
}

void SceneManager::update(float elapsed)
{
    if(currentScene->hasEnded())
    {
        popScene();
    }
    else
    {
	    currentScene->update(elapsed);
    }
}
