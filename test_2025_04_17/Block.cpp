#include "Block.h"
#include "DxLib.h"
#include "GameInfo.h"
#include "BlockManager.h"

	// �R���X�g���N�^
Block::Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument)
	: BoxCollider({ blockArgumentXY})
{
	blockInfo = blockArgument;

	m_downSpeed = 0.7; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ0.7f
	m_lateralSpeed = 3.5; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ3.5f

	m_fillFlag = FALSE;
}

Block::Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement)
	: BoxCollider({ blockArgumentXY })
{
	m_directionOfMove = directionOfMovement;

	blockInfo = blockArgument;

	m_downSpeed = 0.7; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ0.7f
	m_lateralSpeed = 3.5; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ3.5f

	m_fillFlag = FALSE;
}

//�f�X�g���N�^
Block::~Block()
{
	//����
}

// �u���b�N�̉��ړ�
void Block::MoveBlockDown()
{
	collider.y1 += m_downSpeed;
	collider.y2 += m_downSpeed;
}

// �u���b�N�̉��ړ�
void LateralBlock::MoveBlockLateral()
{
	// �R���X�g���N�^�ɓ����������������Ă���𔻒�ɂ��Ă���
	collider.x1 += m_directionOfMove * m_lateralSpeed;
	collider.x2 += m_directionOfMove * m_lateralSpeed;
}

// �`��݂̂����� (�����Ɋւ��Ă� "DrawBox"�@�̕����Q��)
void Block::DrawBlock() const
{
	DrawBox((int)collider.x1, (int)collider.y1, (int)collider.x2, (int)collider.y2, blockInfo.color, blockInfo.fillFlag);
}

void Block::UpdateBlock()
{
	if (!m_onCollision)
	{
		MoveBlockLateral(); // ���ړ�
	}
	else
	{
		MoveBlockDown(); // ���ړ�
		SetFillBlock(); // �u���b�N�̓h��Ԃ�
	}
}

// ��ʊO���̔���
bool Block::IsOffScreen() const
{
	// ��ӂ���ʉ���艺�̏ꍇ�@�E�ӂ���ʍ��[�T�O���W��菭�Ȃ��Ƃ��@���ӂ���ʉE�{�Q�O�O���W��葽���Ƃ��ɏ�����
	// ���E�{�Q�O�O�ɂ��Ă���̂͐������Ă��������Ȃ��悤�ɂ��邽�߁i���㑝�₷�����j�@
	return collider.y1 > WIN_SIZE_Y || collider.x2 < -200 || collider.x1 > WIN_SIZE_X + 200;
}

// �u���b�N�̐F����
void Block::SetFillBlock()
{
	blockInfo.fillFlag = TRUE;
}


void Block::CollisionEnter(BoxCollider* other)
{
	SetOnCollisionTrue();
}