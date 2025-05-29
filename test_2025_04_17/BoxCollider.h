#pragma once

#include "GameInfo.h"

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollisionEnter; // �����蔻��

public:
	// �R���X�g���N�^
	BoxCollider(ColliderInfo collider);

	// �f�X�g���N�^
	virtual ~BoxCollider();

	//�����蔻��
	bool OnCollision();

	ColliderInfo GetCclliderInfo();
};