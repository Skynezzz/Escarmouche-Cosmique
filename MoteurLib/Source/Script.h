#pragma once
#include "Component.h"

class Script : public Component
{
public:
	Script();
	~Script() override;

	int Update() override;

private:

};