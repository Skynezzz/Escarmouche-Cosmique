#pragma once
#include "pch.h"

class GameObject
{

public: 

	GameObject() {};
	virtual ~GameObject() {};

private :

	void Identity();
	void FromMatrix(MATRIX* pMat);
	void UpdateRotationFromVectors();
	void UpdateRotationFromQuaternion();
	void UpdateRotationFromMatrix();
	void UpdateMatrix();

	void Rotate(float yaw, float pitch, float roll);
	void RotateYaw(float angle);
	void RotatePitch(float angle);
	void RotateRoll(float angle);
	void RotateWorld(MATRIX* pMatrix);
	void RotateWorldX(float angle);
	void RotateWorldY(float angle);
	void RotateWorldZ(float angle);

};

struct TRANSFORM {
	VECTOR3 vSca;
	MATRIX mSca;

	VECTOR3 vDir;
	VECTOR3 vRight;
	VECTOR3 vUp;
	QUATERNION qRot;
	MATRIX mRot;

	VECTOR3 vPos;
	MATRIX mRot;

	MATRIX matrix;
};

