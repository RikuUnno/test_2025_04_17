#pragma once
#include "GameInfo.h"
#include "Block.h"

// 左移動ブロック
class LateralBlock : public Block
{
private:
	int m_directionOfMove;

public:
	// コンストラクタ
	LateralBlock(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement);

	// デストラクタ
	virtual ~LateralBlock();

private:
	// 左右移動
	void MoveBlockLateral() override;

};

