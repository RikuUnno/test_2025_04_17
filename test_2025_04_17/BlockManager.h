#pragma once
#include "GameInfo.h"
#include "Block.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // ブロックの管理用list
	int m_createTimer; // 生成タイマー
	const int m_createInterval = 120; // 例: 120フレームごと
	int	m_verticalRange; // 生成される縦の範囲

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // 生成用　*破棄の使用がdeleteなので引数にはnewを使わないとめっちゃバグる

	void UpDateBlocks(); // 更新・生成・削除　基本なんでもする

	void UpDateBlockLeft(); // 基本的な左移動用の処理

	void UpDateBlockRight(); // 基本的な右移動の処理
};
