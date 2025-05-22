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
	LateralBlock(BlockInfo block, int directionOfMovement);

	// デストラクタ
	virtual ~LateralBlock();

	// 左移動
	void MoveBlockLateral() override;

	// 描画更新
	void UpdateBlock() override;
};

