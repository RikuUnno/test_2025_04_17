#include "BoxCollider.h"

// �R���X�g���N�^
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
{
	collider = colliderArgument;
	m_onCollision = false;
}

// �f�X�g���N�^
BoxCollider::~BoxCollider()
{

}

// �����蔻��
void BoxCollider::SetOnCollisionTrue()
{
	m_onCollision = true;
}

// �����蔻��
void BoxCollider::SetOnCollisionFalse()
{
	m_onCollision = false;
}

// �R���C�_�[�̃Q�b�^�[
ColliderInfo BoxCollider::GetColliderInfo() const
{
	return collider;
}