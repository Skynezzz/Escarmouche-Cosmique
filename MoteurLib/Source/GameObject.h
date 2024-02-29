#pragma once
#include "pch.h"
#include "maths.h"

class GameObject
{

public: 

	GameObject() {};
	~GameObject() {};
	void Rotate(float yaw, float pitch, float roll);
};



