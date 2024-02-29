#include "pch.h"
#include "GameObject.h"



int GameObject::Update(float deltaTime)
{
    int returnValue = 0;

    for ( auto component = components.begin(); component != components.end(); component++ )
    {
        if ( ( *component )->Update(deltaTime) == 1 )
            returnValue = 1;
    }

    return returnValue;
}