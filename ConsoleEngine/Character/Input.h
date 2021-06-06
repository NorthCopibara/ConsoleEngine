#pragma once

enum Direction
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    DEFAULT
};

class Input
{
public:
    Direction GetInput();
};
