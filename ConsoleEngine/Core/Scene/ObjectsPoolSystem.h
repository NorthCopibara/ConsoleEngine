#pragma once
#include <vector>
#include "../GameObjects/GameObject.h"

class ObjectsPoolSystem
{
public:
    void AddGameObject(GameObject* gameObject);
    std::vector<GameObject*> GetSceneGameObjects();
    //TODO: get by id

private:
    std::vector<GameObject*> _sceneObjects;
};
