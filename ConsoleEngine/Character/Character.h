#pragma once
#include "../Core/Executable.h"
#include "../Core/GameObjects/GameObject.h"

class Character : public Executable, public GameObject
{
public:
    Character(GameObjectModel mode): GameObject(mode){}
    void Execute() override;
};
