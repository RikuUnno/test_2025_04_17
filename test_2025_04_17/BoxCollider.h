#pragma once

#include "GameInfo.h"

class BoxCollider
{
protected:

public:
	// �R���X�g���N�^
	BoxCollider(ColliderInfo);

	// �f�X�g���N�^
	virtual ~BoxCollider();

	//�����蔻��
	void OnCollision();
};