#include "ObjectsPoolSystem.h"

void ObjectsPoolSystem::AddGameObject(GameObject* gameObject)
{
    _sceneObjects.push_back(gameObject);
}

std::vector<GameObject*> ObjectsPoolSystem::GetSceneGameObjects()
{
    return _sceneObjects;
}
