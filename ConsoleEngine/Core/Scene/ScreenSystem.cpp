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
bool CheckWayOutOfSizePlayingField(COORD& currentObjectCoord);
void RenderCharacters(COORD currentObjectCoord, COORD lastObjectCoord, GameObject* object);
void RefreshLastPosition(GameObject* object);
void RefreshCurrentPosition(GameObject* object);

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
            auto currentObjectCoord = CreateCurrentPositionCOORD(object);
            auto lastScreenCoord = CreateLastPositionCOORD(object);

            if (lastScreenCoord.X == currentObjectCoord.X && lastScreenCoord.Y == currentObjectCoord.Y && !object->
                GetChangingState())
                continue;

            if(CheckWayOutOfSizePlayingField(currentObjectCoord))
            {
                RefreshCurrentPosition(object);
                continue;
            }
            RenderCharacters(currentObjectCoord, lastScreenCoord, object);
            RefreshLastPosition(object);

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

bool CheckWayOutOfSizePlayingField(COORD& currentObjectCoord)
{
    return currentObjectCoord.X < 0 || currentObjectCoord.X > DW_SIZE || currentObjectCoord.Y < 0 ||
        currentObjectCoord.Y > HW_SIZE;
}

void RefreshLastPosition(GameObject* object)
{
    auto newPosition = object->GetPosition();
    object->SetLastPosition(newPosition);
}

void RefreshCurrentPosition(GameObject* object)
{
    auto newPosition = object->GetLastPosition();
    object->SetPosition(newPosition);
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
    lastScreenCoord.X = static_cast<short>(object->GetLastPosition().x);
    lastScreenCoord.Y = static_cast<short>(object->GetLastPosition().y);
    return lastScreenCoord;
}
