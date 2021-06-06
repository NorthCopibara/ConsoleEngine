#pragma once
#include "Executable.h"

extern double DeltaTime;

class FrameSystem
{
public:
    void Start();
    void BindExecutableObject(Executable *object);
};
