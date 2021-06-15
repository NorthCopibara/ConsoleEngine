#include "ECSWorld.h"

#include "ECSFilter.h"

void ECSWorld::AddEntity(ECSEntity* entity)
{
    _poolEntities.push_back(entity);

    for (auto filter : _filters)
    {
        filter->AddEntity(entity);
    }
}

void ECSWorld::AddFilter(ECSFilter* filter)
{
    _filters.push_back(filter);
}
