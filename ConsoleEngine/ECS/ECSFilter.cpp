#include "ECSFilter.h"

#include "ECSWorld.h"

ECSFilter::ECSFilter(ECSWorld* world, ECSComponent *componentsBegin, ECSComponent *componentsEnd)
{
    world->AddFilter(this);

    for (auto *ptr = componentsBegin; ptr != componentsEnd; ptr++)
    {
        _filterComponents.push_back(ptr);
    }
}

void ECSFilter::AddEntity(ECSEntity* entity)
{
    for (auto filter : _filterComponents)
    {
        auto resultEntity = entity->GetComponent(filter);

        if(resultEntity != nullptr)
        {
            _entities.push_back(entity);
        }
    }
}

ECSEntity* ECSFilter::GetByComponentId(int id)
{
    return _entities[id];
}

std::vector<ECSEntity*> ECSFilter::Entities()
{
    return _entities;
}
