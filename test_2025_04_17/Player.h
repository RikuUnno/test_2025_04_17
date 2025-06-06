#pragma once
#include "BoxCollider.h"

#include "Block.h"

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

	double m_blockHeight; // �u���b�N��height
	double m_space; // �u���b�N�ƃv���C���[�̊Ԃ̍�

	const char m_ISJUMPING = 0b00001; // �W�����v����
	const char m_ISFALLING = 0b00010; // ��������
	const char m_ISPUSHTOSPACE = 0b00100; // �X�y�[�X�L�[����x�����ꂽ��
	char m_flags; // ��L�O���̃r�b�g���Z�p

	const double m_BLOCKDOUWSPEED = 0.7; // �u���b�N�̗������x
	const double m_HUMPHEIGHTMAX = 200.0; // �ő�W�����v����
	double m_jumpStartY; // �W�����v�J�n����Y���W

	double m_jumpVelocity; // ������
	double m_fallVelocity; // ������

	const double m_JUMP_INIT_SPEED = 20.0; // ����̃X�s�[�h
	const double m_JUMP_GRAVITY = 0.8; // �W�����v�̌���

	const double m_FALL_GRAVITY = 0.2; // �~�����̉���
	const double m_FALL_SUPEED_MAX = 50.0; // �������x�̏��

private:

	// �W�����v�̂��Ă锻��
	void Jumping();

	// �����Ă��锻��
	void Falling();

	// �������Ă���Ƃ��̏����i�g��Ȃ��Ă�����
	void OnCollision(); 

public:
	// �R���X�g���N�^
	Player(PlayerInfo playerArgument);

	// �f�X�g���N�^
	virtual ~Player();

	//�v���C���[�֌W�̍X�V�p
	void UpDatePlayer();

	// �v���C���[�̕`��
	void DrawPlayer() const;

	void SetPosY(double blockHeight);

};