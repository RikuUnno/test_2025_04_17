#pragma once
#include <vector>

class Block;

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollision; // �����蔻��

	std::vector<BoxCollider*> currentHitColliders; // ���݂̃t���[���œ����������
	std::vector<BoxCollider*> previousHitColliders; // �O�t���[���̓����������

public:
	// �R���X�g���N�^
	BoxCollider(ColliderInfo collider);

	// �f�X�g���N�^
	virtual ~BoxCollider();

	void SetOnCollisionTrue() { m_onCollision = true; } // m_onCollision�̃Z�b�^�[

	void SetOnCollisionFalse() { m_onCollision = false; } // m_onCollision�̃Z�b�^�[

	bool GetOnCollision() const { return m_onCollision; } // m_onCollision�̃Q�b�^�[

	ColliderInfo GetColliderInfo() const; // �R���C�_�[�̃Q�b�^�[

	void CheckCollisionEvent(); // �C�x���g�`�F�b�N

	void AddCurrentHitCollider(BoxCollider* box); // currentHitColliders�ɒǉ�

public:
	virtual void CollisionEnter(BoxCollider* other) {} // �ڐG����
	virtual void CollisionStay(BoxCollider* other) {} // �ڐG��
	virtual void CollisionExit(BoxCollider* other) {} // �ڐG�� 
};