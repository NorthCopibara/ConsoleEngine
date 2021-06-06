
#include "Core/FrameSystem.h"
#include "Core/Scene/ScreenSystem.h"
#include "Character/Character.h"

int main(int argc, char* argv[])
{
    ObjectsPoolSystem objectsPoolSystem;
    FrameSystem frame_system;
    ScreenSystem screenSystem;

    //Test character creating
    GameObjectModel characterModel = {0, Updatable, '#', {5, 5}};
    Character *character = new Character(characterModel);
    objectsPoolSystem.AddGameObject(character);
    
    screenSystem.AddGameObjectsPool(objectsPoolSystem.GetSceneGameObjects()); //Initialize rendering
    
    frame_system.BindExecutableObject(character);
    frame_system.BindExecutableObject(&screenSystem); 
    
    frame_system.Start(); //Start frame updating

    return 0;
}
