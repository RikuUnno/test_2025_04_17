#include "BlockManager.h"

BlockManager::BlockManager()
{
	m_createTimer = 0; // 生成タイマー
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
	m_createTimer++; // フレームごとに加算

	if (m_createTimer >= m_createInterval) // 120フレームごとに生成
	{
		int leftOrRight = GetRand(1); // 0～1の値をランダムで決める
		
		if (leftOrRight == LEFT)
		{

		}
		else if (leftOrRight == RIGHT)
		{

		}
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

// ここから～～～　2025_05_15 ～～～

void BlockManager::UpDateBlockLeft()
{
	m_verticalRange = GetRand();
}

void BlockManager::UpDateBlockRight()
{

}