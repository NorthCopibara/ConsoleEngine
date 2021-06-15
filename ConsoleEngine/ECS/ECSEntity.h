#pragma once
#include <vector>

#include "ECSComponent.h"

class ECSEntity
{
public:
    void AddComponent(ECSComponent* component);
    ECSComponent* GetComponent(ECSComponent* component);
    
private:
    std::vector<ECSComponent*> _components;
};
