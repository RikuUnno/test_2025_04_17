#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

class Player : public BoxCollider
{
private:
	PlayerInfo playerInfo;
	const double m_jumpSpeed = 5.0; // �㏸���x
	const double m_gravity = 4.0; // �������x
	const double m_jumpHeightMax = 200.0; // �ő�W�����v����
	bool m_isJumping; // �W�����v����
	bool m_isFalling; // ��������
	bool m_isPushToSpace; // �X�y�[�X�L�[����x�����ꂽ��
	double m_jumpStartY; // �W�����v�J�n����Y���W

public:
	// �R���X�g���N�^
	Player(PlayerInfo playerArgument);

	// �f�X�g���N�^
	virtual ~Player();

	//�v���C���[�֌W�̍X�V�p
	void UpDatePlayer();

	// �v���C���[�̕`��
	void DrawPlayer() const;

	// �W�����v�̂��Ă锻��
	void IsJumping();

	// �����Ă��锻��
	void IsFalling();


};