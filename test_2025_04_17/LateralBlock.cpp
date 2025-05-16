#include "LateralBlock.h"

	// �R���X�g���N�^
LateralBlock::LateralBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag, int directionOfMovement)
	: Block(x1, y1, x2, y2, color, fillFlag)
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
