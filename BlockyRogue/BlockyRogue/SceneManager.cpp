#include "SceneManager.h"

void SceneManager::pushScene(Scene* scene)
{
	scenes.push_back(scene);
	currentScene = scene;
}

void SceneManager::popScene()
{
	if(scenes.size() <= 0)
		return;
	scenes.pop_back();
	currentScene = scenes.back();
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
	currentScene->update(elapsed);
}
