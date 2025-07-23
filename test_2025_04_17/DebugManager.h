#pragma once
#include "Player.h"
#include "BlockManager.h"
#include <string>

struct DebugItem 
{
	std::string label; // 表示されるラベル
	double* valuePtr; // 値
};

class DebugManager
{
private:
	Player* playerPtr = nullptr; // プレイヤーのptr
	BlockManager* blockManagerPtr = nullptr; // ブロックマネージャーのPtr

	std::vector<DebugItem> debugItems; // 変更する値のlist
	int selectedIndex = 0; // 上のIndex
	bool prevUp = false, prevDown = false, prevLeft = false, prevRight = false;

private:
	DebugManager() {} // コンストラクタ

	DebugManager(const DebugManager&) = delete;				// コピコンの禁止
	DebugManager& operator=(const DebugManager&) = delete;	// 代入の禁止

public:
	static DebugManager& GetInstance() {
		static DebugManager instance;
		return instance;
	}

	void Init(Player* player, BlockManager* blockManager);

	void Update();

	void Draw();

};