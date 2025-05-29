#include "Player.h"
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

#ifdef _DEBUG
	std::string timerStr = std::to_string(playerInfo.y);
	DrawString(0, 15, timerStr.c_str(), GetColor(255, 255, 255));
#endif // _DEBUG


	if (!CheckHitKey(KEY_INPUT_SPACE)) // �X�y�[�X�L�[�������Ă�����
	{
		m_flags &= ~m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
	}

	// �X�y�[�X����������W�����v
	if (!(m_flags & m_ISJUMPING) && !(m_flags & m_ISFALLING) 
		&& !(m_flags & m_ISPUSHTOSPACE) && CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags |= m_ISJUMPING; // �W�����v���Ă�
		m_flags |= m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
		m_jumpStartY = playerInfo.y;
	}

	if (m_flags & m_ISJUMPING) // ���ł�����
	{
		Jumping();
	}

	if (m_flags & m_ISFALLING) // �����Ă�����
	{
		Falling();
	}

	DrawPlayer(); // �v���C���[�̕`��
}

// �v���C���[�̕`��
void Player::DrawPlayer() const
{
	DrawGraph((int)playerInfo.x, (int)playerInfo.y, playerInfo.GraphName, playerInfo.TransFlag);
}

// �W�����v�̂��Ă锻��
void Player::Jumping()
{
	playerInfo.y -= m_JUMPSPEED;
	if (playerInfo.y <= m_jumpStartY - m_HUMPHEIGHTMAX || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags &= ~m_ISJUMPING; // �W�����v���Ă��Ȃ�
		m_flags |= m_ISFALLING; // ��
	}
}

// �����Ă锻��
void Player::Falling()
{
	playerInfo.y += m_GRAVITY;
	if (playerInfo.y >= 300) // �����ɓ����蔻��n�̏���������i�����鍂���j
	{
		m_flags &= ~m_ISFALLING; // ��������̏�
	}
}