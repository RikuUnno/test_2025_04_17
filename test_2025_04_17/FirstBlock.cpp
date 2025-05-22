#include "FirstBlock.h"

// 引数はDrawBox関数を参照
// 引数の値は最初にブロックをおきたい位置で
FirstBlock::FirstBlock(BlockInfo block)
		: Block(block)
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
