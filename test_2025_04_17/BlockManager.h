#pragma once
#include "GameInfo.h"
#include "Block.h"
#include "LateralBlock.h"

class BlockManager
{
private:
	BoxCollider* m_player;
	std::vector<Block*> blockList; // ブロックの管理用list
	int m_createTimer; // 生成タイマー
	const int m_CREATEINTERAVL = 300; // 例: 300フレームごと
	int	m_verticalRange; // 生成される縦の範囲
	unsigned int m_blockColor; // 生成するブロックの色を格納

public:
	BlockManager(BoxCollider* player);

	virtual ~BlockManager();

	BlockManager(const BlockManager&) = delete;	// コピーコンストラクタ禁止
	void operator=(const BlockManager&) = delete;	// 代入も禁止

	void AddBlocks(Block* newBlock); // 生成用　*破棄の使用がdeleteなので引数にはnewを使わないとめっちゃバグる

	void UpDateBlocks(); // 更新・生成・削除　基本なんでもする

	void CheckHitCollider(Block* block);

private:
	void UpDateBlockLateral(); // 基本的な横移動用の処理
};
