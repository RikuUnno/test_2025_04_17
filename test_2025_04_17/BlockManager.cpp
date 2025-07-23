#include "BlockManager.h"
#include "DxLib.h"
#include "GameInfo.h"
#include <string>
#include <cmath>

using namespace std;

BlockManager::BlockManager(Player* player, unsigned int triangleCr)
{
	m_createTimer = 0; // 生成タイマー
	m_CreateInteravl = 120; // 生成インターバル
	m_verticalPos = 0; // 生成される縦の範囲
	m_blockColor = 0; // 生成するブロックの色を格納
	boxColliderList.push_back(player); // 最初の一回だけ追加
	m_heightRange = 50;
	m_widthRange = 150;
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

	if (m_createTimer >= m_CreateInteravl) // 120フレームごとに生成
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

	int playerY = (int)player->GetColliderInfo().y1;
	int minY = playerY - 100,
		   maxY = playerY;

	m_verticalPos = GetRand(maxY - minY) + minY; // 縦の位置をランダムで設定

	m_blockColor = GetColor(GetRand(255), GetRand(255), GetRand(255)); // 色をランダムで設定

	if (vx < 0)
	{
		lateralBlockXY = { (double)WIN_SIZE_X, (double)m_verticalPos, WIN_SIZE_X + m_widthRange, (double)m_verticalPos + m_heightRange};
		lateralBlock = {m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}
	else if (vx > 0)
	{
		lateralBlockXY = { -m_widthRange, (double)m_verticalPos, 0, (double)m_verticalPos + m_heightRange};
		lateralBlock = {m_blockColor, FALSE }; // 上記の情報をもとにブロック情報の生成
	}

	AddBlocks(new Block(lateralBlockXY, lateralBlock, vx)); // ブロックの生成

}

// ブロックのリストを使って回したいのでプレイヤークラスを持たせるようにする
void BlockManager::CheckHitCollider(Block* block, Player* player)
{
	ColliderInfo p = player->GetColliderInfo();
	ColliderInfo b = block->GetColliderInfo();

	boxColliderList.push_back(block);

	// 仮想の当たり判定をブロックの1個分上に置く
	ColliderInfo virtualBlock;
	double height = b.y2 - b.y1;

	virtualBlock.x1 = b.x1 + 10;
	virtualBlock.x2 = b.x2 - 10;
	virtualBlock.y1 = b.y1 - height + 15;  // 1個分上に
	virtualBlock.y2 = b.y1;           // ブロックの上辺まで

	// 「プレイヤーの当たり判定の上端（y1）」を下に下げる（頭を当たり判定から外す）
	double playerHeight = p.y2 - p.y1;
	double reduceHead = playerHeight * 0.5f;  // 上半分を無効化（＝真ん中から下だけ当たり判定）

	p.y1 += reduceHead;

	// 中心点からの距離
	double dx = std::fabs(((p.x1 + p.x2) / 2.0) - ((virtualBlock.x1 + virtualBlock.x2) / 2.0));
	double dy = std::fabs(((p.y1 + p.y2) / 2.0) - ((virtualBlock.y1 + virtualBlock.y2) / 2.0));

	// 判定サイズ
	double abHW = (((p.x2 - p.x1) / 2.0) + (virtualBlock.x2 - virtualBlock.x1) / 2);
	double abHH = (((p.y2 - p.y1) / 2.0) + (virtualBlock.y2 - virtualBlock.y1) / 2);

#ifdef _DEBUG
	// プレイヤーの当たり判定：緑
	DrawBox(
		(int)(p.x1),
		(int)(p.y1),
		(int)(p.x2),
		(int)(p.y2),
		GetColor(0, 255, 0),
		FALSE  // 塗りつぶし false = 枠線のみ
	);

	// 仮想の乗れる判定：赤
	DrawBox(
		(int)(virtualBlock.x1),
		(int)(virtualBlock.y1),
		(int)(virtualBlock.x2),
		(int)(virtualBlock.y2),
		GetColor(255, 0, 0),
		FALSE
	);

	DrawLine((int)b.x1 - 30, (int)b.y1, (int)b.x2 + 30, (int)b.y1, GetColor(255, 142, 241));
#endif

	if (dx < abHW && dy < abHH)
	{
		block->AddCurrentHitCollider(player);
		player->AddCurrentHitCollider(block);

#ifdef _DEBUG
		DrawFormatString(0, 75, GetColor(255, 255, 255), "当たり");
#endif //_DEBUG

	}
}

 // 上の関数をmain関数で回すやつ
 void BlockManager::CheckHitColliderAll(Player* player)
 {
	 for (Block* block : blockList)
	 {
		 if(block != nullptr) CheckHitCollider(block, player);
	 }

	 for (BoxCollider* block : boxColliderList)
	 {
		 block->CheckCollisionEvent();
	 }

	 // プレイヤー以外のブロックをlistから削除
	boxColliderList.erase(
		 std::remove_if(boxColliderList.begin(), boxColliderList.end(),
			 [](BoxCollider* collider) {
				 // Player* にキャストできなければ削除対象
				 return dynamic_cast<Player*>(collider) == nullptr;
			 }),
		boxColliderList.end()
	 );
 }

 // 描画処理
 void BlockManager::DrawBlocks() const
 {
	 for (const Block* block : blockList)
	 {
		 if(block != nullptr) block->DrawBlock();
	 }
 }

 void BlockManager::Reset(Player* player, unsigned int triangleCr)
 {
	 // ブロックを全て削除
	 for (Block* block : blockList)
	 {
		 if (block != nullptr)
		 {
			 delete block;
		 }
	 }
	 blockList.clear();

	 // コライダーリストをプレイヤーのみに
	 boxColliderList.clear();
	 boxColliderList.push_back(player);

	 // 各種値も初期化
	 m_createTimer = 0;
	 m_CreateInteravl = 120;
	 m_verticalPos = 0;
	 m_heightRange = 50;
	 m_widthRange = 150;

	 // 初期ブロックを1つ設置する
	 AddBlocks(new Block({ WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150 }, { triangleCr, TRUE }));
 }