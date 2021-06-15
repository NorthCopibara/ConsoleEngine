#pragma once
#include <vector>

#include "ECSEntity.h"

class ECSFilter;

class ECSWorld
{
public:
    void AddEntity(ECSEntity* entity);
    void AddFilter(ECSFilter* filter);

private:
    std::vector<ECSEntity*> _poolEntities;
    std::vector<ECSFilter*> _filters;
};
