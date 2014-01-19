#include "Scene.h"

Scene::Scene(std::string sceneName)
{
	name = sceneName;
}

std::string Scene::getName()
{
	return name;
}