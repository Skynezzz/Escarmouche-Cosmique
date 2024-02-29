#include "GameObject.h"
#include "pch.h"

template<typename T>
T* GameObject::AddComponent()
{
    for ( Component* component : components )
    {
        if ( dynamic_cast< T* >(component) != nullptr )
        {
            return dynamic_cast< T* >(component);
        }
    }

    T* newComponent = new T();
    components.push_back(newComponent);

    return newComponent;
}

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

D3D12_HEAP_PROPERTIES
D3D12_RESSOURCES_DESC
D3D12_RESSOURCES_BARRIER