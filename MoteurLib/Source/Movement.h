#pragma once
#include "Component.h"

class Movement : public Component
{
public:
	Movement();
	~Movement() override;

	int Update() override;

private:

	void SetDirection();
	void Move();

};