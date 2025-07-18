#include "BoxCollider.h"

// �R���X�g���N�^
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
	:collider(colliderArgument), m_onCollision(false)
{}

BoxCollider::~BoxCollider()
{}

// �R���C�_�[�̃Q�b�^�[
ColliderInfo BoxCollider::GetColliderInfo() const
{
	return collider;
}

void BoxCollider::AddCurrentHitCollider(BoxCollider* box)
{
    currentHitColliders.push_back(box);
}

void BoxCollider::CheckCollisionEvent()
{
    for (BoxCollider* other : currentHitColliders)
    {
        if (std::find(previousHitColliders.begin(), previousHitColliders.end(), other) == previousHitColliders.end())
        {
            CollisionEnter(other); // ���߂ē�������
        }
        else
        {
            CollisionStay(other); // �O�������������Ă�
        }
    }

    for (BoxCollider* other : previousHitColliders)
    {
        if (std::find(currentHitColliders.begin(), currentHitColliders.end(), other) == currentHitColliders.end())
        {
            CollisionExit(other); // ����͓������Ă��Ȃ�
        }
    }

    previousHitColliders = currentHitColliders; // �O�̏�Ԃ��X�V
    currentHitColliders.clear(); // ���̏�Ԃ͏�����
}