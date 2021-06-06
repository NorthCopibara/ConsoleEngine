#include "GameObject.h"

GameObject::GameObject(GameObjectModel model)
{
    isChanging = true;
    gameObject = model;
}

unsigned long GameObject::GetId()
{
    return gameObject.Id;
}

GameObjectType GameObject::GetType()
{
    return gameObject.Type;
}

char GameObject::GetRenderChar()
{
    return gameObject.RenderChar;
}

Vector3 GameObject::GetPosition()
{
    return gameObject.Position;
}

Vector3 GameObject::GetLastPosition()
{
    return lastPosition;
}

void GameObject::SetPosition(Vector3 &pos)
{
    gameObject.Position = pos;
}

void GameObject::SetLastPosition(Vector3& pos)
{
    lastPosition = pos;
}

bool GameObject::GetChangingState()
{
    return isChanging;
}

void GameObject::ResetChanging()
{
    isChanging = false;
}
