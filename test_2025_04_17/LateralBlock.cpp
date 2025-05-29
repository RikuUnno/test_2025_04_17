#include "LateralBlock.h"

	// コンストラクタ
LateralBlock::LateralBlock(BlockInfo blockArgument, int directionOfMovement)
	: Block(blockArgument)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// 左右移動
void LateralBlock::MoveBlockLateral()
{
	// コンストラクタに動く方向を持たせてそれを判定にしている
		blockInfo.x1 += m_directionOfMove * m_lateralSpeed;
		blockInfo.x2 += m_directionOfMove * m_lateralSpeed;
	
}

void LateralBlock::UpdateBlock()
{
	// if("ここに当たった判定を入れる")
	// {
	MoveBlockLateral(); // 横移動
	// }
	// else
	// {
	// MoveBlockDown(); // 下移動
	// m_fillFlag = true; // ブロックの塗りつぶし
	// }
	DrawBlock(); // 描画
}
