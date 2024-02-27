#pragma once
#include "Component.h"

class Movement : public Component
{
public:
	Movement();
	~Movement() override;


	void SetDirection();
	void Move();

private:

};