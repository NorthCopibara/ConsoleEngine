#pragma once

#include <windows.h>

enum GameObjectType
{
    Static,
    Updatable
};

struct Vector3
{
    double x;
    double y;
    double z;
};

struct GameObjectModel
{
    unsigned long Id;
    GameObjectType Type;
    char RenderChar;
    Vector3 Position;
};

class GameObject
{
public:
    GameObject(GameObjectModel model);

    unsigned long GetId();
    GameObjectType GetType();
    char GetRenderChar();
    
    Vector3 GetPosition();
    Vector3 GetLastPosition();
    
    void SetPosition(Vector3 &pos);
    void SetLastPosition(Vector3 &pos);
    
    bool GetChangingState();
    void ResetChanging();

protected:
    bool isChanging;
    Vector3 lastPosition;
    GameObjectModel gameObject;
};
