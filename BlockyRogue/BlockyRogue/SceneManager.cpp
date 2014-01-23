#include "SceneManager.hpp"
Scene* SceneManager::currentScene;
std::list<Scene*> SceneManager::scenes;
std::list<Scene*> SceneManager::scenesToRemove;

void SceneManager::pushScene(Scene* scene)
{
	scenes.push_back(scene);
	currentScene = scene;
}

void SceneManager::popScene()
{
	if(scenes.size() <= 0)
		return;
	scenesToRemove.push_back(scenes.back());
	scenes.pop_back();
	if(!scenes.empty())
		currentScene = scenes.back();
    //TODO: Shouldn't there be clean up for the removed scene?
}

void SceneManager::removeScene(Scene* scene)
{
	scenesToRemove.push_back(scenes.back());
	currentScene = scenes.back();
}

void SceneManager::draw(sf::RenderWindow* window, sf::View view)
{
	if(scenes.empty())
	{
		window->close();
		return;
	}
	currentScene->draw(window, view);
}

void SceneManager::update(float elapsed)
{
	if(!scenes.empty())
		currentScene->update(elapsed);

	//Delete removed scenes after update
	for (std::list<Scene*>::iterator it = scenesToRemove.begin(); !scenesToRemove.empty();)
	{
		delete *it;
		it = scenesToRemove.erase(it);
	}
}
