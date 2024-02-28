#pragma once
#include "Component.h"

class MeshRenderer : public Component
{
public:
	MeshRenderer();
	~MeshRenderer() override;

	int Update() override;

private:

};