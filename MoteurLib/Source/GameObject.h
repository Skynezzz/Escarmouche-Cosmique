#pragma once
#include <vector>
#include "Component.h"
#include "Maths.h"

class GameObject
{

public: 

	GameObject() {};
	~GameObject() {};
	void Rotate(float yaw, float pitch, float roll);

	template<typename T>
	T* AddComponent();

	int Update(float deltaTime);

private:

	std::vector<Component*> components;
	TRANSFORM transform;

};

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
