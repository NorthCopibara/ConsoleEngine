#include "FrameSystem.h"

#include <ctime>
#include <iostream>
#include <vector>
#include <windows.h>

#include "Executable.h"

double DeltaTime;
clock_t dTime = 0;
unsigned int frames = 0;
double frameRate = 30;
std::vector<Executable*> _executablesObject;

void StartFrameUpdating();
void ExecuteMain();

void FrameSystem::Start()
{
    StartFrameUpdating();
}

void FrameSystem::BindExecutableObject(Executable* object)
{
    _executablesObject.push_back(object);
}

double ClockToMilliseconds(clock_t ticks)
{
    return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
}

void ExecuteMain()
{
    for (auto& object : _executablesObject)
    {
        object->Execute();
    }
    //std::cout << frameRate << std::endl;
}

void StartFrameUpdating()
{
    while (true)
    {
        clock_t beginFrame = clock();
        ExecuteMain();
        Sleep(1);
        clock_t endFrame = clock();

        dTime += endFrame - beginFrame;
        frames ++;

        if (ClockToMilliseconds(dTime) > 1000.0)
        {
            frameRate = (double)frames * 0.5 + frameRate * 0.5;
            DeltaTime = 1 / frameRate;
            frames = 0;
            dTime -= CLOCKS_PER_SEC;
        }
    }
}
