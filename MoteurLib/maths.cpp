#include "pch.h"
#include "maths.h"

void TRANSFORM::Identity()
{
	vSca.x = 1.0f;
	vSca.y = 1.0f;
	vSca.z = 1.0f;

	mSca._11 = 1;
	mSca._22 = 1;
	mSca._33 = 1;
	mSca._44 = 1;

	vFor.x = 1.0f;
	vFor.y = 0.0f;
	vFor.z = 0.0f;

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

}
