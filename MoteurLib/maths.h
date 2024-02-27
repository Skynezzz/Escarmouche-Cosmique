#pragma once

class TRANSFORM {

public:

	void Identity();

private:

	XMFLOAT3 vSca;
	XMFLOAT4X4 mSca;

	XMFLOAT3 vFor;
	XMFLOAT3 vRight;
	XMFLOAT3 vUp;
	XMFLOAT4 qRot;
	XMFLOAT4X4 mRot;

	XMFLOAT3 vPos;
	XMFLOAT4X4 mPos;

	XMFLOAT4X4 matrix;
};