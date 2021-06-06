#include "ScreenSystem.h"

#include <iostream>
#include <vector>
#include <windows.h>

#include "../GameObjects/GameObject.h"

//TODO: move static to new class
static const int DW_SIZE = 100;
static const int HW_SIZE = 30;

std::vector<GameObject*> _sceneObjects;
HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

COORD CreateLastPositionCOORD(GameObject* object);
COORD CreateCurrentPositionCOORD(GameObject* object);
void CheckWayOutOfSizePlayingField(COORD currentObjectCoord, GameObject* object);
void RenderCharacters(COORD currentObjectCoord, COORD lastObjectCoord, GameObject* object);

ScreenSystem::ScreenSystem()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(_hConsole, &info);
}

void ScreenSystem::AddGameObjectsPool(std::vector<GameObject*> gameObjects)
{
    _sceneObjects = gameObjects;
}

void ScreenSystem::Execute()
{
    //TODO: create static objects on start scene

    for (auto& object : _sceneObjects)
    {
        if (object->GetType() == Updatable)
        {
            const auto CurrentObjectCoord = CreateCurrentPositionCOORD(object);
            const auto LastScreenCoord = CreateLastPositionCOORD(object);

            if (LastScreenCoord.X == CurrentObjectCoord.X && LastScreenCoord.Y == CurrentObjectCoord.Y && !object->
                GetChangingState())
                continue;

            CheckWayOutOfSizePlayingField(CurrentObjectCoord, object);
            RenderCharacters(CurrentObjectCoord, LastScreenCoord, object);

            object->ResetChanging();
        }
    }
}

void RenderCharacters(COORD currentObjectCoord, COORD lastObjectCoord, GameObject* object)
{
    SetConsoleCursorPosition(_hConsole, currentObjectCoord);
    std::cout << object->GetRenderChar();

    const auto isNewObject = !(lastObjectCoord.X != currentObjectCoord.X || lastObjectCoord.Y != currentObjectCoord.Y);
    if (!isNewObject)
    {
        SetConsoleCursorPosition(_hConsole, lastObjectCoord);
        std::cout << " ";
    }
}

void CheckWayOutOfSizePlayingField(COORD currentObjectCoord, GameObject* object)
{
    auto position = object->GetPosition();
    if (currentObjectCoord.X <= 0)
    {
        position.x = DW_SIZE - 1;
        object->SetPosition(position);
    }
    if (currentObjectCoord.X >= DW_SIZE)
    {
        position.x = 0;
        object->SetPosition(position);
    }

    if (currentObjectCoord.Y <= 0)
    {
        position.y = HW_SIZE - 1;
        object->SetPosition(position);
    }
    if (currentObjectCoord.Y >= HW_SIZE)
    {
        position.y = 0;
        object->SetPosition(position);
    }

    object->SetLastPosition(position);
}

COORD CreateCurrentPositionCOORD(GameObject* object)
{
    COORD screenCoord;
    screenCoord.X = static_cast<short>(object->GetPosition().x);
    screenCoord.Y = static_cast<short>(object->GetPosition().y);
    return screenCoord;
}

COORD CreateLastPositionCOORD(GameObject* object)
{
    COORD lastScreenCoord;
    lastScreenCoord.X = static_cast<short>(object->GetPosition().x);
    lastScreenCoord.Y = static_cast<short>(object->GetPosition().y);
    return lastScreenCoord;
}
