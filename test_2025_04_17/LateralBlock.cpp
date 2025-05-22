#include "LateralBlock.h"

	// �R���X�g���N�^
LateralBlock::LateralBlock(BlockInfo block, int directionOfMovement)
	: Block(block)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// ���ړ�
void LateralBlock::MoveBlockLateral()
{
	// �R���X�g���N�^�ɓ����������������Ă���𔻒�ɂ��Ă���
	if (m_directionOfMove == LEFT)
	{
		blockInfo.x1 -= m_lateralSpeed;
		blockInfo.x2 -= m_lateralSpeed;
	}
	else if (m_directionOfMove == RIGHT)
	{
		blockInfo.x1 += m_lateralSpeed;
		blockInfo.x2 += m_lateralSpeed;
	}
}

void LateralBlock::UpdateBlock()
{
	MoveBlockLateral(); // ���ړ�

	DrawBlock(); // �`��
}
