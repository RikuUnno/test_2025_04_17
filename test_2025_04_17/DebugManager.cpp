#include "DebugManager.h"
#include "DXLib.h"
#include "gameinfo.h"
#include <vector>

void DebugManager::Init(Player* player, BlockManager* blockManager)
{
	playerPtr = player;
	blockManagerPtr = blockManager;

	debugItems.push_back({ "ブロック生成間隔", &blockManagerPtr->GetCreateInteravl() });
	debugItems.push_back({ "ブロックの縦の大きさ", &blockManagerPtr->GetHeightRange() });
	debugItems.push_back({ "ブロックの横の大きさ", &blockManagerPtr->GetWidthRange() });
	debugItems.push_back({ "ジャンプの最大高度", &playerPtr->GetHumpHeightMax() });
	debugItems.push_back({ "ジャンプの初手の力", &playerPtr->GetJumpInitSpeed() });
	debugItems.push_back({ "ジャンプの減速率", &playerPtr->GetJumpGravity() });
	debugItems.push_back({ "落下加速率", &playerPtr->GetFallGravity() });
	debugItems.push_back({ "落下加速率の上限", &playerPtr->GetFallSupeedMax() });
}

void DebugManager::Update()
{
	// 入力取得
	bool up = CheckHitKey(KEY_INPUT_UP);
	bool down = CheckHitKey(KEY_INPUT_DOWN);
	bool left = CheckHitKey(KEY_INPUT_LEFT);
	bool right = CheckHitKey(KEY_INPUT_RIGHT);

	// 選択項目の変更（上下キー）
	if (up && !prevUp) {
		selectedIndex--;
		if (selectedIndex < 0) selectedIndex = static_cast<int>(debugItems.size()) - 1;
	}
	if (down && !prevDown) {
		selectedIndex++;
		if (selectedIndex >= debugItems.size()) selectedIndex = 0;
	}

	// 選択中の値を増減（左右キー）
	if (!debugItems.empty()) {
		double& value = *debugItems[selectedIndex].valuePtr;
		if (right && !prevRight) {
			value += 1.0; // 増やす値
		}
		if (left && !prevLeft) {
			value -= 1.0; // 減らす値
		}
	}

	// 入力の前フレーム値を更新
	prevUp = up;
	prevDown = down;
	prevLeft = left;
	prevRight = right;
}

void DebugManager::Draw()
{
	int x = 0;
	int y = 0;
	int lineHeight = 24;

	for (int i = 0; i < debugItems.size(); ++i) {
		const DebugItem& item = debugItems[i];
		int color = (i == selectedIndex) ? GetColor(255, 255, 0) : GetColor(255, 255, 255);
		DrawFormatString(x, y + i * lineHeight, color, "%s : %.1f", item.label.c_str(), *item.valuePtr);
	}
	DrawFormatString(x, (int)debugItems.size() * lineHeight, GetColor(255, 255, 255), "ESCで戻る");
	
}