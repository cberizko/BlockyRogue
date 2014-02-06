#ifndef _SCENEMANAGER_HPP
#define _SCENEMANAGER_HPP
#include "Scene.hpp"
#include <iostream>
#include <list>

class SceneManager
{
	public:
        ~SceneManager();
		static void pushScene(Scene* scene);
		static void popScene();
		static void removeScene(Scene* scene);
		static void update(float elapsed);
		static void draw(sf::RenderWindow* window, sf::View view);

	private:
		static Scene* currentScene;
		static std::list<Scene*> scenes;
		static std::list<Scene*> scenesToRemove;
};

#endif
