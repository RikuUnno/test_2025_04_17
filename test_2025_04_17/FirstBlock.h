#pragma once

#include "GameInfo.h"
#include "Block.h"

// 最初に出てくるブロックのクラス メモ(多分次から出てくるブロックのやつもいれるかも(その場合は名前変更必須)
class FirstBlock : public Block
{
public:
	// 引数はDrawBox関数を参照
	// 引数の値は最初にブロックをおきたい位置で
	FirstBlock(BlockInfo blockArgument);

	virtual ~FirstBlock();
	
private:
	// 最初のブロックの降下用のアップデート関数
	void UpdateBlock() override;

};