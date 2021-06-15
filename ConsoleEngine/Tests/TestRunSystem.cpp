#include "TestRunSystem.h"

#include <iostream>

#include "Test1Component.h"
#include "../ECS/ECSWorld.h"
#include "../ECS/ECSFilter.h"

ECSFilter* _filter;
Test1Component _t1;

TestRunSystem::TestRunSystem(ECSWorld* world): ECSRunSystem(world)
{
    
    ECSComponent components[] = {_t1};
    _filter = new ECSFilter(world, std::begin(components), std::end(components));
}

void TestRunSystem::Run()
{
    for (auto element : _filter->Entities())
    {
        Test1Component test = element->GetComponent(&_t1); //TODO: get by templait

        std::cout << test.;
    }
}
