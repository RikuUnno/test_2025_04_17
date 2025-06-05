#include "BlockManager.h"
#include "DxLib.h"
#include <string>
#include <cmath>

using namespace std;

BlockManager::BlockManager()
{
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
}

void BlockManager::AddBlocks(Block* newBlock)
{
	// ブロックの生成
	blockList.push_back(newBlock);
}

void BlockManager::UpDateBlocks(BoxCollider* player)
{
	// 生成処理
	m_createTimer++; // フレームごとに加算

#ifdef _DEBUG
	string timerStr = to_string(m_createTimer);
	DrawString(0, 0, timerStr.c_str(), GetColor(255, 255, 255));
#endif // _DEBUG

	if (m_createTimer >= m_CREATEINTERAVL) // 120フレームごとに生成
	{
		UpDateBlockLateral(player);
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

void BlockManager::UpDateBlockLateral(BoxCollider* player)
{
	ColliderInfo lateralBlockXY = { 0, 0, 0, 0 };
	BlockInfo lateralBlock = { 0, 0 };
	int vx = -1 + 2 * GetRand(1); // -1,1の値をランダムで決める

	m_verticalRange = GetRand(player->GetColliderInfo().y2 -170) + 150 ; // 縦の位置をランダムで設定

	m_blockColor = GetColor(GetRand(255), GetRand(255), GetRand(255)); // 色をランダムで設定

	// ColliderInfo lateralBlockXY = { -100, m_verticalRange , 0, m_verticalRange + 50};
	// BlockInfo lateralBlock = {m_blockColor, FALSE};

	if (vx < 0)
	{
		lateralBlockXY = { WIN_SIZE_X, (double)m_verticalRange, WIN_SIZE_X + 125, (double)m_verticalRange + 50};
		lateralBlock = {m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}
	else if (vx > 0)
	{
		lateralBlockXY = { -125, (double)m_verticalRange, 0, (double)m_verticalRange + 50};
		lateralBlock = {m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}

	AddBlocks(new LateralBlock(lateralBlockXY, lateralBlock, vx)); // ブロックの生成

}

// ブロックのリストを使って回したいのでプレイヤークラスを持たせるようにする
 void BlockManager::CheckHitCollider(Block* block, BoxCollider* player)
{
		ColliderInfo p = player->GetColliderInfo();
		ColliderInfo b = block->GetColliderInfo();

#ifdef _DEBUG
		DrawFormatString(0, 45, GetColor(255, 255, 255), "当たり判定P.y2:%lf ", p.y2);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "当たり判定B.y1:%lf ", b.y1);
#endif // _DEBUG

		//それぞれの中心点からの距離を求める
		double dx = std::fabs(((p.x1 + p.x2) / 2.0) - ((b.x1 + b.x2) / 2.0));
		double dy = std::fabs(((p.y1 + p.y2) / 2.0) - ((b.y1 + b.y2) / 2.0));

		// それぞれの半分を足した長さを求める
		double abHW = (((p.x2 - p.x1) / 2.0) + (b.x2 - b.x1) / 2);
		double abHH = (((p.y2 - p.y1) / 2.0) + (b.y2 - b.y1) / 2);

		if (dx < abHW && dy < abHH)
		{
 			if (p.y2 <= b.y1 + (b.y2 - b.y1) * 0.15)
			{
				player->SetOnCollisionTrue();
				block->SetOnCollisionTrue(); // ブロックの当たり判定を変更（ブロック関係がfalseに戻ることは今のところない）
			}
#ifdef _DEBUG
			DrawFormatString(0, 75, GetColor(255, 255, 255), "当たり");
#endif // _DEBUG
		}
}

 // 上の関数をmain関数で回すやつ
 void BlockManager::CheckHitColliderAll(BoxCollider* player)
 {
	 for (Block* block : blockList)
	 {
		 if(block != nullptr) CheckHitCollider(block, player);
	 }

 }

 // 描画処理
 void BlockManager::DrawBlocks() const
 {
	 for (const Block* block : blockList)
	 {
		 if(block != nullptr) block->DrawBlock();
	 }
 }
