#pragma once
#include "ECSWorld.h"
#include "../Core/Executable.h"

class ECSRunSystem : public Executable
{
public:
    ECSRunSystem(ECSWorld* world);
    
    
private:
    ECSWorld* _world;
    void Execute() override;
    virtual void Run() = 0;
};
