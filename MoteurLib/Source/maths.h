#pragma once

class TRANSFORM {

public:

	void Identity();

	void Rotate(float yaw, float pitch, float roll);

	void Scale(float x, float y, float z);

	void Position(float x, float y, float z);

	void updateMatrix();

private:

	XMFLOAT3 vSca;
	XMFLOAT4X4 mSca;

	XMFLOAT3 vDir;
	XMFLOAT3 vRight;
	XMFLOAT3 vUp;
	XMFLOAT4 qRot;
	XMFLOAT4X4 mRot;

	XMFLOAT3 vPos;
	XMFLOAT4X4 mPos;

	XMFLOAT4X4 matrix;
};