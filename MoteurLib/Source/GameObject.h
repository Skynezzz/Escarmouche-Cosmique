#pragma once
#include <vector>
#include "Component.h"
#include "Maths.h"

class GameObject
{

public: 

	GameObject() {};
	~GameObject() {};
<<<<<<< HEAD
	void Rotate(float yaw, float pitch, float roll);
};
=======

	template<typename T>
	T* AddComponent();
>>>>>>> 06f004f7d84d3ea227f36d3c934a9c3e9876652e

	int Update(float deltaTime);

private:

	std::vector<Component*> components;
	TRANSFORM transform;

};