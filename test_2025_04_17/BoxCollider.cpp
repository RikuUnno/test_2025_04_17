#include "BoxCollider.h"

// �R���X�g���N�^
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
{
	collider = colliderArgument;
	m_onCollisionEnter = false;
}

// �f�X�g���N�^
BoxCollider::~BoxCollider()
{

}

//�����蔻��
bool BoxCollider::OnCollision()
{
	return 0; // (��)
}

ColliderInfo BoxCollider::GetCclliderInfo()
{
	return collider;
}