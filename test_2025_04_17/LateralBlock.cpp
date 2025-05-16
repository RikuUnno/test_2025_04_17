#include "LateralBlock.h"

	// コンストラクタ
LateralBlock::LateralBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag, int directionOfMovement)
	: Block(x1, y1, x2, y2, color, fillFlag)
{
	m_directionOfMove = directionOfMovement;
}

LateralBlock::~LateralBlock()
{}

// 左移動
void LateralBlock::MoveBlockLateral()
{
	// コンストラクタに動く方向を持たせてそれを判定にしている
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
	MoveBlockLateral(); // 左移動

	DrawBlock(); // 描画
}
