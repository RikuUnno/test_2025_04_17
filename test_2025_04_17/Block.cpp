#include "Block.h"

	// コンストラクタ
Block::Block(BlockInfo block)
{
	blockInfo = block;

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
	// memo FirstBlockClassに実装を書かないといけなくなるのでとりあえず仮想関数（別の動きをするブロックを作るときは変えたほうがいいかも）
}

// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
void Block::DrawBlock()
{
	DrawBox((int)blockInfo.x1, (int)blockInfo.y1, (int)blockInfo.x2, (int)blockInfo.y2, blockInfo.color, blockInfo.fillFlag);
}

// 画面外かの判定
bool Block::IsOffScreen() const
{
	// 上辺が画面下より下の場合　右辺が画面左ー５０座標より少ないとき　左辺が画面右＋５０座標より多いときに消える
	// 左右＋５０にしているのは生成してすぐ消えないようにするため（今後増やすかも）　
	return blockInfo.y1 > WIN_SIZE_Y || blockInfo.x2 < -200 || blockInfo.x1 > WIN_SIZE_X + 200;
}

