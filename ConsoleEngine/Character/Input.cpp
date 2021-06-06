#include <conio.h>
#include <iostream>
#include "Input.h"

Direction Input::GetInput()
{
    if(!_kbhit()) return DEFAULT;
    
    switch (_getch()) {
    case 'w':
        return UP;
    case 'd':
        return RIGHT;
    case 's':
        return DOWN;
    case 'a':
        return LEFT;
    default:
        return DEFAULT;
    }
}
