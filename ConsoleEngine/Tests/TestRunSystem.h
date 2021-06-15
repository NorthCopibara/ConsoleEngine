#pragma once
#include "../ECS/ECSRunSystem.h"


class TestRunSystem : public ECSRunSystem
{
public:
    TestRunSystem(ECSWorld* world);

private:
    void Run() override;
};
