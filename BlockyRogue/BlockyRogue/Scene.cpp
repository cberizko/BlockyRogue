#include "Scene.hpp"

Scene::Scene(std::string sceneName)
{
	name = sceneName;
}

Scene::~Scene()
{
}

std::string Scene::getName()
{
	return name;
}
