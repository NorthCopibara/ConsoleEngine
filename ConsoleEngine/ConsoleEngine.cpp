
#include "Core/FrameSystem.h"
#include "Core/Scene/ScreenSystem.h"
#include "Character/Character.h"

int main(int argc, char* argv[])
{
    ObjectsPoolSystem objectsPoolSystem;
   
    FrameSystem frame_system;

    //Test character creating
    GameObjectModel testCharacterModel = {0, Updatable, '#', {0, 0}};
    Character *character = new Character(testCharacterModel);
    objectsPoolSystem.AddGameObject(character);
    
    ScreenSystem screenSystem;
    screenSystem.AddGameObjectsPool(objectsPoolSystem.GetSceneGameObjects()); //Initialize rendering
    
    frame_system.BindExecutableObject(character);
    frame_system.BindExecutableObject(&screenSystem); 
    
    frame_system.Start(); //Start frame updating

    return 0;
}
