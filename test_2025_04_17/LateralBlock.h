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
	LateralBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag, int directionOfMovement);

	// デストラクタ
	virtual ~LateralBlock();

	// 左移動
	void MoveBlockLateral() override;

	// 描画更新
	void UpdateBlock() override;
};

