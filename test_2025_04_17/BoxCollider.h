#pragma once

#include "GameInfo.h"

class BoxCollider
{
protected:
	bool m_onCollisionEnter; // �����蔻��

public:
	// �R���X�g���N�^
	BoxCollider(ColliderInfo collider);

	// �f�X�g���N�^
	virtual ~BoxCollider();

	//�����蔻��
	bool OnCollision();
};