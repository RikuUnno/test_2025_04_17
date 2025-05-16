#include "FirstBlock.h"

// 引数はDrawBox関数を参照
// 引数の値は最初にブロックをおきたい位置で
FirstBlock::FirstBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: Block(x1, y1, x2, y2, color, fillFlag)
{
	DrawBlock(); // 描画処理
}

FirstBlock::~FirstBlock()
{}

// 最初のブロックの降下用のアップデート関数
void FirstBlock::UpdateBlock()
{
	// ここに消す判定のメンバ関数を入れる

	MoveBlockDown(); // 下がっていく処理

	DrawBlock(); // 描画処理
}
