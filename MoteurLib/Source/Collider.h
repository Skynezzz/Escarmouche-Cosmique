#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	~Collider();

	void OnCollision();
	void CheckCollision();

private:

};