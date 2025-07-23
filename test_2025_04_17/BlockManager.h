#pragma once
#include "DxLib.h"
#include "Block.h"
#include "Player.h"
#include "BoxCollider.h"
#include <vector>

class BlockManager
{
private:
	std::vector<Block*> blockList; // ブロックの管理用list
	std::vector<BoxCollider*> boxColliderList; // 当たったコライダーのイベントチェック用
	double m_createTimer; // 生成タイマー
	double m_CreateInteravl; // インターバル	
	double m_verticalPos; // 生成される縦の位置
	double m_heightRange;
	double m_widthRange; // 生成される横の範囲
	unsigned int m_blockColor; // 生成するブロックの色を格納

public:
	double& GetCreateInteravl() { return m_CreateInteravl; }
	double& GetHeightRange() { return m_heightRange; }
	double& GetWidthRange() { return m_widthRange; }
	 
public:
	BlockManager(Player* player, unsigned int triangleCr);

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

public:
	void Reset(Player* player, unsigned int triangleCr); // リセット用
};
