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
	LateralBlock(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement);

	// �f�X�g���N�^
	virtual ~LateralBlock();

private:
	// ���E�ړ�
	void MoveBlockLateral() override;

};

