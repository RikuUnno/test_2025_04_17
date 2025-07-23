#include "Player.h"
#include "DxLib.h"
#include "GameManager.h"
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
	m_jumpVelocity = 0.0; // ������
	m_fallVelocity = 0.0; // ������

	m_blockHeight = 0.0; // �u���b�N��height
	m_space = collider.y2 - collider.y1; // �v���C���[y1��y2�̊Ԃ̍�
	blockHeight = 0;
}

// �f�X�g���N�^
Player::~Player()
{}

//�v���C���[�֌W�̍X�V�p
void Player::UpDatePlayer()
{

	if (!CheckHitKey(KEY_INPUT_SPACE)) // �X�y�[�X�L�[�������Ă�����
	{
		m_flags &= ~m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
	}

	// �X�y�[�X����������W�����v
	if (!(m_flags & m_ISJUMPING) && !(m_flags & m_ISFALLING) &&
		!(m_flags & m_ISPUSHTOSPACE) && CheckHitKey(KEY_INPUT_SPACE) )
	{
		m_flags |= m_ISJUMPING; // �W�����v���Ă�
		m_flags |= m_ISPUSHTOSPACE; // ��x�������痣���܂ōē��͂���Ȃ�
		SetOnCollisionFalse(); // �����蔻��̉���
		m_jumpStartY = collider.y1;
		m_jumpVelocity = m_JumpInitSpeed; // �����Z�b�g	
	}

	if (m_onCollision)
	{
		m_flags &= ~m_ISJUMPING; // �W�����v�����Ă��Ȃ�
		m_flags &= ~m_ISFALLING; // �󒆂ł��Ȃ�
		m_flags &= ~m_ISFALLING; // ��������̏�
		m_fallVelocity = 0.0; // ������~�i�Ȃɂ����̏�
		collider.y1 += m_BLOCKDOUWSPEED,
		collider.y2 += m_BLOCKDOUWSPEED; // �v���C���[�̂����̕ύX
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

void Player::CollisionEnter(BoxCollider* other)
{
	blockHeight = other->GetColliderInfo().y1;
	SetPosY();
	SetOnCollisionTrue(); // �u���b�N�Ɠ������x
	currentColliderPtr = other;
	if (currentColliderPtr != prevColliderPtr) GameManager::GetInstance().SetPoint(1);
}

void Player::CollisionExit(BoxCollider* other)
{
	prevColliderPtr = other;
}

// �W�����v�̂��Ă锻��
void Player::Jumping()
{
#ifdef _DEBUG
	DrawFormatString(0, 90, GetColor(255, 255, 255), "Jumping");
#endif // _DEBUG

	collider.y1 -= m_jumpVelocity, 
	collider.y2 -= m_jumpVelocity; // �v���C���[�̂����̕ύX
	m_jumpVelocity -= m_JumpGravity; // ���t���[������

	if (collider.y1 <= m_jumpStartY - m_HumpHeightMax || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags &= ~m_ISJUMPING; // �W�����v���Ă��Ȃ�
		m_flags |= m_ISFALLING; // �����Ă���
		m_fallVelocity = 0.0;
	}
}

// �����Ă锻��
void Player::Falling()
{ 
#ifdef _DEBUG
	DrawFormatString(0, 105, GetColor(255, 255, 255), "Falling");
#endif // _DEBUG

	if (m_onCollision) // �����ɓ����蔻��n�̏���������i�����鍂���j
	{}
	else
	{
		m_fallVelocity += m_FallGravity;
		if (m_fallVelocity > m_FallSupeedMax) m_fallVelocity = m_FallSupeedMax; // ���̑��x�ɂȂ������������߂�
		
		collider.y1 += m_fallVelocity,
		collider.y2 += m_fallVelocity; // �v���C���[�̂����̕ύX
	}
}

void Player::SetPosY()
{
	collider.y2 = blockHeight;	
	collider.y1 = collider.y2 - m_space;
}

void Player::Reset()
{
	// collider�i���W�j�������ʒu�Ƀ��Z�b�g
	int sizeXBuf = 0, sizeYBuf = 0;
	GetGraphSize(playerInfo.GraphName, &sizeXBuf, &sizeYBuf);
	collider = ColliderInfo{
		playerInfo.x,
		playerInfo.y,
		playerInfo.x + sizeXBuf,
		playerInfo.y + sizeYBuf
	};

	// �e��ϐ���������
	m_flags = 0;
	m_jumpStartY = 0.0;
	m_jumpVelocity = 0.0;
	m_fallVelocity = 0.0;
	m_blockHeight = 0.0;
	m_space = sizeYBuf;
	blockHeight = 0.0;
	SetOnCollisionFalse();
}