#include "Player.h"
#include "DxLib.h"
#include <string>

// �R���X�g���N�^
Player::Player(PlayerInfo playerArgument)
	: BoxCollider([&]() // �����_�� �@BoxCollider�̈����ɓ���邽�߂̒l�̌v�Z
		{
			int sizeXBuf = 0, sizeYBuf = 0; // �摜�̃T�C�Y��ێ�����ϐ��i��񂫂�j
			GetGraphSize(playerArgument.GraphName, &sizeXBuf, &sizeYBuf); // �摜�̃T�C�Y���擾���Ċi�[

			// �e�N���X�̃R���X�g���N�^�����Ɋi�[
			return ColliderInfo{
				playerArgument.x,
				playerArgument.y,
				playerArgument.x + sizeXBuf,
				playerArgument.y + sizeYBuf
			};
		}())
{ // �`�`�`��������R���X�g���N�^�̒��g�`�`�`��
	playerInfo = playerArgument; // �R���X�g���N�^�����̏���ۑ�
	m_flags = 0; // (0b00000000)
	m_jumpStartY = 0.0; // �W�����v�J�n����Y���W
}

// �f�X�g���N�^
Player::~Player()
{

}

//�v���C���[�֌W�̍X�V�p
void Player::UpDatePlayer()
{
	if (!CheckHitKey(KEY_INPUT_SPACE)) // �X�y�[�X�L�[�������Ă�����
	{
		m_flags &= ~m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
	}

	// �X�y�[�X����������W�����v
	if (!(m_flags & m_ISJUMPING) && !(m_flags & m_ISFALLING) 
		&& !(m_flags & m_ISPUSHTOSPACE) && CheckHitKey(KEY_INPUT_SPACE) )
	{
		m_flags |= m_ISJUMPING; // �W�����v���Ă�
		m_flags |= m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
		m_jumpStartY = collider.y1;
		SetOnCollisionFalse();
	}

	if (m_flags & m_ISJUMPING) // ���ł�����
	{
		Jumping();
	}

	if (!(m_flags & m_ISJUMPING)) // �����Ă�����
	{
		Falling();
	}
}

// �v���C���[�̕`��
void Player::DrawPlayer() const
{
	DrawGraph((int)collider.x1, (int)collider.y1, playerInfo.GraphName, playerInfo.TransFlag);
}

// �W�����v�̂��Ă锻��
void Player::Jumping()
{
	collider.y1 -= m_JUMPSPEED, collider.y2 -= m_JUMPSPEED; // �v���C���[�̂����̕ύX
	if (collider.y1 <= m_jumpStartY - m_HUMPHEIGHTMAX || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags &= ~m_ISJUMPING; // �W�����v���Ă��Ȃ�
		m_flags |= m_ISFALLING; // �����Ă���
	}
	else if (m_onCollision)
	{
		OnCollision();
		m_flags &= ~m_ISJUMPING; // �W�����v�����Ă��Ȃ�
		m_flags &= ~m_ISFALLING; // �󒆂ł��Ȃ�
	}
}

// �����Ă锻��
void Player::Falling()
{
	if (m_onCollision && !(m_flags & m_ISJUMPING)) // �����ɓ����蔻��n�̏���������i�����鍂���j
	{
		OnCollision();
		m_flags &= ~m_ISFALLING; // ��������̏�
	}
	else
	{
		collider.y1 += m_GRAVITY, collider.y2 += m_GRAVITY; // �v���C���[�̂����̕ύX
	}
}

void Player::OnCollision()
{
	collider.y1 += m_BLOCKDOUWSPEED, collider.y2 += m_BLOCKDOUWSPEED; // �u���b�N�Ɠ������x
}