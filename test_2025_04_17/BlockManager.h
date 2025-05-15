#pragma once
#include "GameInfo.h"
#include "Block.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // ブロックの管理用list
	int createTimer; // 生成タイマー
	const int createInterval = 120; // 例: 120フレームごと

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // 生成用　*破棄の使用がdeleteなので引数にはnewを使わないとめっちゃバグる

	void UpDateBlocks(); // 更新・生成・削除　基本なんでもする
};
