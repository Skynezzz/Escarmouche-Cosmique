#pragma once
#include <vector>
#include "Component.h"
#include "Maths.h"

class GameObject
{

public: 

	GameObject() {};
	~GameObject() {};

	template<typename T>
	T* AddComponent();

	int Update(float deltaTime);

private:

	std::vector<Component*> components;
	TRANSFORM transform;

};