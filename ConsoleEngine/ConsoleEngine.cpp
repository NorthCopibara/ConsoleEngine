
#include <iostream>

#include "Core/FrameSystem.h"
#include "Core/Scene/ScreenSystem.h"
#include "Character/Character.h"
#include "ECS/ECSWorld.h"
#include "Tests/Test1Component.h"
#include "Tests/Test2Component.h"
#include "Tests/TestRunSystem.h"

int main(int argc, char* argv[])
{
    //ObjectsPoolSystem objectsPoolSystem;
    FrameSystem frame_system;
    ScreenSystem screenSystem;

    //Test character creating
    /*GameObjectModel characterModel = {0, Updatable, '#', {5, 5}};
    Character *character = new Character(characterModel);
    objectsPoolSystem.AddGameObject(character);*/
    
    //screenSystem.AddGameObjectsPool(objectsPoolSystem.GetSceneGameObjects()); //Initialize rendering
    
    //frame_system.BindExecutableObject(character);
    //frame_system.BindExecutableObject(&screenSystem); 

    ECSWorld *ptr_world = new ECSWorld();
    
    
    //Сначала системы с фильтрами
    TestRunSystem run1(ptr_world);
    frame_system.BindExecutableObject(&run1);
    

    //Потом инициализация энтити
    ECSEntity entity;
    Test1Component com1;
    Test2Component com2;
    entity.AddComponent(&com1);
    entity.AddComponent(&com2);
    ptr_world->AddEntity(&entity);
    

    
    frame_system.Start(); //Start frame updating


    
    return 0;
}
