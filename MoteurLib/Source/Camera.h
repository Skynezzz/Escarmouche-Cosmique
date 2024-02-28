#pragma once
#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera() override;

	int Update() override;

private:

};