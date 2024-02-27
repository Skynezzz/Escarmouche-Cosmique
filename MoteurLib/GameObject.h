#pragma once
#include "pch.h"
#include "maths.h"

class GameObject
{

public: 

	GameObject() {};
	virtual ~GameObject() {};

private :

	void Rotate(float yaw, float pitch, float roll);

};



