#include "BlockManager.h"

#include <string>

using namespace std;

BlockManager::BlockManager(BoxCollider* player)
{
	m_player = player;
	m_createTimer = 0; // 生成タイマー
	m_verticalRange = 0; // 生成される縦の範囲
	m_blockColor = 0; // 生成するブロックの色を格納
}

BlockManager::~BlockManager()
{
	// 全てのブロックを削除
	for (size_t i = 0; i < blockList.size(); i++)
	{
		delete blockList[i];
	}
	blockList.clear();

	m_player = nullptr;
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

#ifdef _DEBUG

	string timerStr = to_string(m_createTimer);
	DrawString(0, 0, timerStr.c_str(), GetColor(255, 255, 255));

#endif // _DEBUG

	if (m_createTimer >= m_CREATEINTERAVL) // 120フレームごとに生成
	{
		UpDateBlockLateral();
		m_createTimer = 0;
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

void BlockManager::UpDateBlockLateral()
{
	BlockInfo lateralBlock = {0,0,0,0,0,0};
	int vx = -1 + 2 * GetRand(1); // -1,1の値をランダムで決める

	m_verticalRange = GetRand(250) + 150; // 縦の位置をランダムで設定

	m_blockColor = GetColor(GetRand(255), GetRand(255), GetRand(255)); // 色をランダムで設定

	// BlockInfo lateralBlock = {-100, m_verticalRange , 0, m_verticalRange + 50, m_blockColor, FALSE};

	if (vx < 0)
	{
		lateralBlock = { WIN_SIZE_X, (double)m_verticalRange, WIN_SIZE_X + 125, (double)m_verticalRange + 50, m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}
	else if (vx > 0)
	{
		lateralBlock = { -125, (double)m_verticalRange, 0, (double)m_verticalRange + 50, m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}

	AddBlocks(new LateralBlock(lateralBlock, vx)); // ブロックの生成

}

//void BlockManager::CheckHitCollider(Block* block)
//{
//	if(m_player->GetCclliderInfo().x2 >= block->GetCclliderInfo().x1 && m_player->GetCclliderInfo().y2)
//}
