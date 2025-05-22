#pragma once
#include "GameInfo.h"
#include "Block.h"
#include "LateralBlock.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // ブロックの管理用list
	int m_createTimer; // 生成タイマー
	const int m_createInterval = 300; // 例: 300フレームごと
	int	m_verticalRange; // 生成される縦の範囲
	unsigned int m_blockColor; // 生成するブロックの色を格納

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // 生成用　*破棄の使用がdeleteなので引数にはnewを使わないとめっちゃバグる

	void UpDateBlocks(); // 更新・生成・削除　基本なんでもする

	void UpDateBlockLateral(int leftOrRight); // 基本的な横移動用の処理
};
