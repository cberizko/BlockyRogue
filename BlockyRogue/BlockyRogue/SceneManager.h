#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H
#include "Scene.h"
#include <iostream>
#include <list>

class SceneManager
{
	public:
		static void pushScene(Scene* scene);
		static void popScene();
		static void removeScene(Scene* scene);
		static void update(float elapsed);
		static void draw(sf::RenderWindow* window);
	private:
		static Scene* currentScene;
		static std::list<Scene*> scenes;
};

#endif