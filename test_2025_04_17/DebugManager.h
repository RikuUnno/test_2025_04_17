#pragma once
#include "Player.h"
#include "BlockManager.h"

class DebugManager
{
private:
	Player* playerPtr = nullptr; 
	BlockManager* blockManagerPtr = nullptr;

private:
	DebugManager(){} // コンストラクタ

	DebugManager(const DebugManager&) = delete;				// コピコンの禁止
	DebugManager& operator=(const DebugManager&) = delete;	// 代入の禁止
	
public:
	static DebugManager& GetInstance() {
		static DebugManager instance;
		return instance;
	}

	void SetPlayer(Player* player) { // PlayerClassのセット
		playerPtr = player;
	}

	void SetBlockManager(BlockManager* blockManager) { // BlockManagerのセット
		blockManagerPtr = blockManager;
	}





}
