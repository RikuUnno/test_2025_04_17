#include "Block.h"

	// コンストラクタ
Block::Block(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
{
	blockInfo = { (float)x1, (float)y1,(float)x2, (float)y2, color, fillFlag };

	m_downSpeed = 0.7f; // どのくらいになるかわからないので一応2
	m_lateralSpeed = 0.7f; // どのくらいになるかわからないので一応2
}

//デストラクタ
Block::~Block()
{
	//未定
}

// ブロックの横移動
void Block::MoveBlockDown()
{
	blockInfo.y1 += m_downSpeed;
	blockInfo.y2 += m_downSpeed;
}

// ブロックの横移動
void Block::MoveBlockLateral()
{
	// 最初のブロックも動いてしまうのでここには書かない
}

// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
void Block::DrawBlock()
{
	DrawBox(blockInfo.x1, blockInfo.y1, blockInfo.x2, blockInfo.y2, blockInfo.color, blockInfo.fillFlag);
}

// 画面外かの判定
bool Block::IsOffScreen() const
{
	// 上辺が画面下より下の場合　右辺が画面左ー５０座標より少ないとき　左辺が画面右＋５０座標より多いときに消える
	// 左右＋５０にしているのは生成してすぐ消えないようにするため（今後増やすかも）　
	return blockInfo.y1 > WIN_SIZE_Y || blockInfo.x2 < -50 || blockInfo.x1 > WIN_SIZE_X + 50;
}

