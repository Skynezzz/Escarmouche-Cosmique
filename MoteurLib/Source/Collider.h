#pragma once
#include "Component.h"

// Structure représentant une boîte englobante
struct BoundingBox
{
	XMFLOAT3 min; // Coin inférieur de la boîte
	XMFLOAT3 max; // Coin supérieur de la boîte
};

// Structure représentant une sphère englobante
struct BoundingSphere {
	XMFLOAT3 center; // Centre de la sphère
	float radius;    // Rayon de la sphère
};

class Collider : public Component
{
public:
	Collider();
	~Collider() override;

	int Update(float deltaTime) override;

private:

	bool IsCollisionBox(const BoundingBox&, const BoundingBox&);
	bool IsCollisionSphere(const BoundingSphere&, const BoundingSphere&);

};