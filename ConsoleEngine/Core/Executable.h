#pragma once

class Executable
{
public:
    virtual ~Executable() = default;
    virtual void Execute() = 0;
};
