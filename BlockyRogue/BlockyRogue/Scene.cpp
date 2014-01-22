#include "Scene.hpp"

Scene::Scene(std::string sceneName)
{
	name = sceneName;
    sceneHasEnded = false;
}

Scene::~Scene()
{
}

std::string Scene::getName()
{
	return name;
}

bool Scene::hasEnded()
{
    return sceneHasEnded;
}
