#include "LateralBlock.h"

	// �R���X�g���N�^
LateralBlock::LateralBlock(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement)
	: Block(blockArgumentXY, blockArgument)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// ���E�ړ�
void LateralBlock::MoveBlockLateral()
{
	// �R���X�g���N�^�ɓ����������������Ă���𔻒�ɂ��Ă���
	collider.x1 += m_directionOfMove * m_lateralSpeed;
	collider.x2 += m_directionOfMove * m_lateralSpeed;
	
}

void LateralBlock::UpdateBlock()
{
	if(!m_onCollision)
	{
	MoveBlockLateral(); // ���ړ�
	}
	else
	{
	MoveBlockDown(); // ���ړ�
	SetFillBlock(); // �u���b�N�̓h��Ԃ�
	}
}


