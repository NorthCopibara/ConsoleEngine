#include "Character.h"
#include "Input.h"
#include "../Core/FrameSystem.h"

Input input;
int speed = 50;

void Character::Execute()
{
    switch (input.GetInput())
    {
    case UP:
        gameObject.Position.y -= speed * DeltaTime;
        break;
    case DOWN:
        gameObject.Position.y += speed * DeltaTime;
        break;
    case RIGHT:
        gameObject.Position.x += speed * DeltaTime;
        break;
    case LEFT:
        gameObject.Position.x -= speed * DeltaTime;
        break;
    default: ;
    }
}
