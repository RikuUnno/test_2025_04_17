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
	LateralBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag, int directionOfMovement);

	// �f�X�g���N�^
	virtual ~LateralBlock();

	// ���ړ�
	void MoveBlockLateral() override;

	// �`��X�V
	void UpdateBlock() override;
};

