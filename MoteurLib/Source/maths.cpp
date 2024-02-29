#include "maths.h"
#include "pch.h"

void TRANSFORM::Identity()
{
	vSca.x = 1.0f;
	vSca.y = 1.0f;
	vSca.z = 1.0f;

	mSca._11 = 1;
	mSca._22 = 1;
	mSca._33 = 1;
	mSca._44 = 1;

	vDir.x = 1.0f;
	vDir.y = 0.0f;
	vDir.z = 0.0f;

	vRight.x = 0.0f;
	vRight.y = 0.0f;
	vRight.z = 1.0f;

	vUp.x = 0.0f;
	vUp.y = 1.0f;
	vUp.z = 0.0f;

	qRot.w = 0.0f;
	qRot.x = 0.0f;
	qRot.y = 0.0f;
	qRot.z = 1.0f;

	mRot = mSca;

	vPos = vSca;

	mPos = mRot;

	matrix = mRot;
}


void TRANSFORM::Rotate(float yaw, float pitch, float roll)
{
	// load nos vecteurs
	XMVECTOR vDirTemp = XMLoadFloat3(&vDir);
	XMVECTOR vRightTemp = XMLoadFloat3(&vRight);
	XMVECTOR vUpTemp = XMLoadFloat3(&vUp);

	XMVECTOR quat;
	XMVECTOR quatCombine;

	quat = XMQuaternionRotationAxis(vDirTemp, roll);
	quatCombine = quat;

	quat = XMQuaternionRotationAxis(vRightTemp, pitch);
	quatCombine = XMQuaternionMultiply(quatCombine, quat);

	quat = XMQuaternionRotationAxis(vUpTemp, yaw);
	quatCombine = XMQuaternionMultiply(quatCombine, quat);

	XMVECTOR qRotTemp = XMLoadFloat4(&qRot);
	qRotTemp = XMQuaternionMultiply(qRotTemp, quatCombine);
	XMStoreFloat4(&qRot, qRotTemp);

	XMMATRIX mRotTemp;
	mRotTemp = XMMatrixRotationQuaternion(qRotTemp);
	XMStoreFloat4x4(&mRot, mRotTemp);

	vDir.x = mRot._11;
	vDir.y = mRot._12;
	vDir.z = mRot._13;
	vRight.x = mRot._21;
	vRight.y = mRot._22;
	vRight.z = mRot._23;
	vUp.x = mRot._31;
	vUp.y = mRot._32;
	vUp.z = mRot._33;

}

void TRANSFORM::Scale(float x, float y, float z)
{
	vSca.x = x;
	vSca.y = y;
	vSca.z = z;

	XMMATRIX mScaTemp = XMMatrixScaling(vSca.x,vSca.y,vSca.z);

	XMStoreFloat4x4(&mSca, mScaTemp);
}

void TRANSFORM::Position(float x, float y, float z)
{
	vPos.x = x;
	vPos.y = y;
	vPos.z = z;

	XMMATRIX mPosTemp = XMMatrixTranslation(vPos.x, vPos.y, vPos.z);

	XMStoreFloat4x4(&mPos, mPosTemp);
}

void TRANSFORM::updateMatrix()
{
	XMMATRIX mScaTemp = XMLoadFloat4x4(&mSca);
	XMMATRIX mRotTemp = XMLoadFloat4x4(&mRot);
	XMMATRIX mPosTemp = XMLoadFloat4x4(&mPos);

	XMMATRIX matrixTemp = XMMatrixMultiply(mScaTemp, mRotTemp);
	matrixTemp = XMMatrixMultiply(matrixTemp, mPosTemp);

	XMStoreFloat4x4(&matrix, matrixTemp);
}
