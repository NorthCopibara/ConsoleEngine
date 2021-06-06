#pragma once
#include "ObjectsPoolSystem.h"
#include "../Executable.h"


class ScreenSystem : public Executable
{
public:
    ScreenSystem();
    void AddGameObjectsPool(std::vector<GameObject*> gameObjects);
    void Execute() override;
};
