#include "ECSEntity.h"
#include <iostream>

void ECSEntity::AddComponent(ECSComponent* component)
{
    for (auto element : _components)
    {
        if (typeid(&element) == typeid(&component)) return;
    }

    _components.push_back(component);
}

ECSComponent* ECSEntity::GetComponent(ECSComponent* component)
{
    for (auto element : _components)
    {
        if(typeid(&component) == typeid(element)) return element;
    }

    return nullptr;
}
