#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

struct PlayerInfo
{
	double x, y; // ���[�h�����摜��`�悷���`�̍��㒸�_�̍��W
	int GraphName; // �摜�n���h���[
	int TransFlag; // �摜�̓����x��L���ɂ��邩�ǂ���
};

class Player : public BoxCollider
{
private:
	PlayerInfo playerInfo;
	const double m_JUMPSPEED = 5.0; // �㏸���x
	const double m_GRAVITY = 4.0; // �������x
	const double m_HUMPHEIGHTMAX = 200.0; // �ő�W�����v����
	const char m_ISJUMPING = 0b00001; // �W�����v����
	const char m_ISFALLING = 0b00010; // ��������
	const char m_ISPUSHTOSPACE = 0b00100; // �X�y�[�X�L�[����x�����ꂽ��
	char m_flags; // ��L�O���̃r�b�g���Z�p
	double m_jumpStartY; // �W�����v�J�n����Y���W

private:

	// �W�����v�̂��Ă锻��
	void Jumping();

	// �����Ă��锻��
	void Falling();

public:
	// �R���X�g���N�^
	Player(PlayerInfo playerArgument);

	// �f�X�g���N�^
	virtual ~Player();

	//�v���C���[�֌W�̍X�V�p
	void UpDatePlayer();

	// �v���C���[�̕`��
	void DrawPlayer() const;
};