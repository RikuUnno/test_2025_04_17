#pragma once
#include "DxLib.h"
#include "Block.h"
#include "Player.h"
#include "LateralBlock.h"
#include <vector>

class BlockManager
{
private:
	std::vector<Block*> blockList; // ブロックの管理用list
	int m_createTimer; // 生成タイマー
	const int m_CREATEINTERAVL = 120; // 例: 120フレームごと
	double	m_verticalRange; // 生成される縦の範囲
	unsigned int m_blockColor; // 生成するブロックの色を格納

public:
	BlockManager();

	virtual ~BlockManager();

	BlockManager(const BlockManager&) = delete;	// コピーコンストラクタ禁止
	void operator=(const BlockManager&) = delete;	// 代入も禁止

	void AddBlocks(Block* newBlock); // 生成用　*破棄の使用がdeleteなので引数にはnewを使わないとめっちゃバグる

	void UpDateBlocks(BoxCollider* player); // 更新・生成・削除　基本なんでもする

	void CheckHitColliderAll(Player* player); // CheckHitColliderメソッドをmainで回すための関数

	void DrawBlocks() const; // ブロックリストを使って描画
private:
	void CheckHitCollider(Block* block, Player* player); // 当たり判定(一個)

	void UpDateBlockLateral(BoxCollider* player); // 基本的な横移動用の処理
};
