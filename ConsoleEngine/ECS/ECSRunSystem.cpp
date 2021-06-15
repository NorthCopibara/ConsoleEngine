#include "ECSRunSystem.h"

void ECSRunSystem::Execute()
{
      Run();
}

ECSRunSystem::ECSRunSystem(ECSWorld* world)
{
      _world = world;
}
