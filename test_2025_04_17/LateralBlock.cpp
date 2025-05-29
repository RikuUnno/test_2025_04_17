#include "LateralBlock.h"

	// �R���X�g���N�^
LateralBlock::LateralBlock(BlockInfo blockArgument, int directionOfMovement)
	: Block(blockArgument)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// ���E�ړ�
void LateralBlock::MoveBlockLateral()
{
	// �R���X�g���N�^�ɓ����������������Ă���𔻒�ɂ��Ă���
		blockInfo.x1 += m_directionOfMove * m_lateralSpeed;
		blockInfo.x2 += m_directionOfMove * m_lateralSpeed;
	
}

void LateralBlock::UpdateBlock()
{
	// if("�����ɓ����������������")
	// {
	MoveBlockLateral(); // ���ړ�
	// }
	// else
	// {
	// MoveBlockDown(); // ���ړ�
	// m_fillFlag = true; // �u���b�N�̓h��Ԃ�
	// }
	DrawBlock(); // �`��
}
