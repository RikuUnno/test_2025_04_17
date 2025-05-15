#include "BlockManager.h"

BlockManager::BlockManager()
{
	createTimer = 0; // 生成タイマー
}

BlockManager::~BlockManager()
{
	// 全てのブロックを削除
	for (size_t i = 0; i < blockList.size(); i++)
	{
		delete blockList[i];
	}
	blockList.clear();
}

void BlockManager::AddBlocks(Block* newBlock)
{
	// ブロックの生成
	blockList.push_back(newBlock);
}

void BlockManager::UpDateBlocks()
{
	// 生成処理
	createTimer++; // フレームごとに加算

	if (createTimer >= createInterval) // 120フレームごとに生成
	{
		// ここから～～～　2025_05_15 ～～～
	}
	

	// 破棄と更新処理

	// 関数のポインタでリスを管理をして削除などをできるようにする
	std::vector<Block*>::iterator it = blockList.begin();

	while (it != blockList.end())
	{
		Block* block = *it;
		block->UpdateBlock(); // ブロックの座標の更新

		if (block->IsOffScreen())
		{
			if (block != nullptr)
			{
				delete block; // ブロック本体の削除
				block = nullptr;
			}
			it = blockList.erase(it); // リストからの削除
		}
		else
		{
			++it; // リストの更新
		}

	}
}
