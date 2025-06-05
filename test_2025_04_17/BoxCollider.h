#pragma once

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollision; // �����蔻��

public:
	// �R���X�g���N�^
	BoxCollider(ColliderInfo collider);

	// �f�X�g���N�^
	virtual ~BoxCollider();

	void SetOnCollisionTrue(); // m_onCollision�̃Z�b�^�[

	void SetOnCollisionFalse(); // m_onCollision�̃Z�b�^�[

	ColliderInfo GetColliderInfo() const; // �R���C�_�[�̃Q�b�^�[
};