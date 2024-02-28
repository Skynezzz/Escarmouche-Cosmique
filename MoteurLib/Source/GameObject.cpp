#include "pch.h"
#include "GameObject.h"


void GameObject::Rotate(float yaw, float pitch, float roll)
{

	// // créer un quaternion à chaque rotation
	//D3DXQUATERNION quat;
	//D3DXQuaternionRotationAxis(&quat,&m_vDir, roll);
	//quatRot = quat;
	//D3DXQuaternionRotationAxis(&quat,&m_vRight, pitch);
	//quatRot *= quat;	
	//D3DXQuaternionRotationAxis(&quat,&m_vUp, yaw);
	//quatRot *= quat;

	// //Ajouter la rotation delta a la rotation actuelle
	//m_quatRot *= quatRot;

	// //Convertir le quaternion en une matrice de roation
	//D3DXMATRIX matRot;
	//D3DXMatrixRotationQuternion(&matRot, &m_quatRot);

	// //Mettre a jour les axes de notre objet
	//m_vRight.x = matRot._11;
	//m_vRight.y = matRot._21;
	//m_vRight.z = matRot._31;
	//m_vUp.x = matRot._21;
	//m_vUp.y = matRot._22;
	//m_vUp.z = matRot._23;
	//m_vDir.x = matRot._31;
	//m_vDir.y = matRot._32;
	//m_vDir.z matRot._33;



	XMVECTOR XM_CALLCONV XMLoadFloat4(const XMFLOAT4 * qRot);

	void XM_CALLCONV XMStoreFloat4(XMFLOAT4 * qRot, FXMVECTOR V);
}
