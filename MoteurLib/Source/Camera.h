#pragma once
#include "Component.h"
#include "pch.h"

class Camera : public Component
{
public:
	Camera();
	~Camera() override;

<<<<<<< HEAD
	DirectX::XMVECTOR GetPosition(); //Calculs Rapides
	DirectX::XMFLOAT3 GetPosition3F(); //Stockages Informations

	void SetPosition(float x, float y, float z);
	void SetPosition3F(const DirectX::XMFLOAT3 vector);

	DirectX::XMVECTOR GetRight()const; //Calc
	DirectX::XMFLOAT3 GetRight3F()const; //Stockage
	DirectX::XMVECTOR GetUp()const; //Calc
	DirectX::XMFLOAT3 GetUp3F()const; //Stockage
	DirectX::XMVECTOR GetLook()const; //Calc
	DirectX::XMFLOAT3 GetLook3F()const; //Stockage

	int Update() override;
=======
	int Update(float deltaTime) override;
>>>>>>> 06f004f7d84d3ea227f36d3c934a9c3e9876652e

private:

};