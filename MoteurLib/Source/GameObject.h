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