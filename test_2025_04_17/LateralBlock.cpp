#include "LateralBlock.h"

	// コンストラクタ
LateralBlock::LateralBlock(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement)
	: Block(blockArgumentXY, blockArgument)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// 左右移動
void LateralBlock::MoveBlockLateral()
{
	// コンストラクタに動く方向を持たせてそれを判定にしている
	collider.x1 += m_directionOfMove * m_lateralSpeed;
	collider.x2 += m_directionOfMove * m_lateralSpeed;
	
}

void LateralBlock::UpdateBlock()
{
	if(!m_onCollision)
	{
	MoveBlockLateral(); // 横移動
	}
	else
	{
	MoveBlockDown(); // 下移動
	SetFillBlock(); // ブロックの塗りつぶし
	}
}


