#pragma once
#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	~Camera() override;

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

	int Update(float deltaTime) override;

private:

};