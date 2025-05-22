#pragma once
#include "GameInfo.h"
#include "Block.h"

// ���ړ��u���b�N
class LateralBlock : public Block
{
private:
	int m_directionOfMove;

public:
	// �R���X�g���N�^
	LateralBlock(BlockInfo block, int directionOfMovement);

	// �f�X�g���N�^
	virtual ~LateralBlock();

	// ���ړ�
	void MoveBlockLateral() override;

	// �`��X�V
	void UpdateBlock() override;
};

