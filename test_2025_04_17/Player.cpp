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
{
	playerInfo = playerArgument; // �R���X�g���N�^�����̏���ۑ�
	m_isJumping = false; // �W�����v����
	m_isFalling = false; // ��������
	m_isPushToSpace = false; // �X�y�[�X�L�[����x�����ꂽ��
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


	if (!CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isPushToSpace = false; // ��x�������痣���܂ōē��͂���Ȃ�
	}

	// �X�y�[�X����������W�����v
	if (!m_isJumping && !m_isFalling && CheckHitKey(KEY_INPUT_SPACE) && !m_isPushToSpace)
	{
		m_isJumping = true; // �W�����v���Ă�
		m_isPushToSpace = true; // ��x�������痣���܂ōē��͂���Ȃ�
		m_jumpStartY = playerInfo.y;
	}

	if (m_isJumping)
	{
		IsJumping();
	}

	if (m_isFalling)
	{
		IsFalling();
	}


	DrawPlayer(); // �v���C���[�̕`��
}

// �v���C���[�̕`��
void Player::DrawPlayer() const
{
	DrawGraph((int)playerInfo.x, (int)playerInfo.y, playerInfo.GraphName, playerInfo.TransFlag);
}

// �W�����v�̂��Ă锻��
void Player::IsJumping()
{
	playerInfo.y -= m_jumpSpeed;
	if (playerInfo.y <= m_jumpStartY - m_jumpHeightMax || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isJumping = false; // �W�����v���Ă��Ȃ�
		m_isFalling = true; // ��
	}
}

// �����Ă锻��
void Player::IsFalling()
{
	playerInfo.y += m_gravity;
	if (playerInfo.y >= 300) // �����ɓ����蔻��n�̏���������i�����鍂���j
	{
		m_isFalling = false; // ��������̏�
	}
}