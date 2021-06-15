#pragma once
#include <vector>

#include "ECSComponent.h"
#include "ECSEntity.h"


class ECSWorld;

class ECSFilter
{
public:
    ECSFilter(ECSWorld* world, ECSComponent *componentsBegin, ECSComponent *componentsEnd);
    void AddEntity(ECSEntity* entity);
    ECSEntity* GetByComponentId(int id);
    std::vector<ECSEntity*> Entities();

private:
    std::vector<ECSComponent*> _filterComponents;
    std::vector<ECSEntity*> _entities;
};
