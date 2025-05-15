#pragma once

#include "GameInfo.h"
#include "Block.h"

// 最初に出てくるブロックのクラス メモ(多分次から出てくるブロックのやつもいれるかも(その場合は名前変更必須)
class FirstBlock : public Block
{
public:
	// 引数はDrawBox関数を参照
	// 引数の値は最初にブロックをおきたい位置で
	FirstBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag);

	virtual ~FirstBlock();
	
	// 最初のブロックの降下用のアップデート関数
	void UpdateBlock() override;

};