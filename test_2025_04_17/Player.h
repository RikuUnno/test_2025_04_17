#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

class Player : public BoxCollider
{
private:


public:
	// �R���X�g���N�^
	Player(PlayerInfo);

	// �f�X�g���N�^
	virtual ~Player();

	//�v���C���[�֌W�̍X�V�p
	void UpDatePlayer();

	// �v���C���[�̕`��
	void DrawPlayer();

	// �v���C���[�̈ړ�


};