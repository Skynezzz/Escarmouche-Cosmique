#pragma once
#include "Component.h"

class Movement : public Component
{
public:
	Movement();
	~Movement() override;

	int Update(float deltaTime) override;

private:

	void SetDirection();
	void Move();

};