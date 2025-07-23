#include "DebugManager.h"
#include "DXLib.h"
#include "gameinfo.h"
#include <vector>

void DebugManager::Init(Player* player, BlockManager* blockManager)
{
	playerPtr = player;
	blockManagerPtr = blockManager;

	debugItems.push_back({ "�u���b�N�����Ԋu", &blockManagerPtr->GetCreateInteravl() });
	debugItems.push_back({ "�u���b�N�̏c�̑傫��", &blockManagerPtr->GetHeightRange() });
	debugItems.push_back({ "�u���b�N�̉��̑傫��", &blockManagerPtr->GetWidthRange() });
	debugItems.push_back({ "�W�����v�̍ő卂�x", &playerPtr->GetHumpHeightMax() });
	debugItems.push_back({ "�W�����v�̏���̗�", &playerPtr->GetJumpInitSpeed() });
	debugItems.push_back({ "�W�����v�̌�����", &playerPtr->GetJumpGravity() });
	debugItems.push_back({ "����������", &playerPtr->GetFallGravity() });
	debugItems.push_back({ "�����������̏��", &playerPtr->GetFallSupeedMax() });
}

void DebugManager::Update()
{
	// ���͎擾
	bool up = CheckHitKey(KEY_INPUT_UP);
	bool down = CheckHitKey(KEY_INPUT_DOWN);
	bool left = CheckHitKey(KEY_INPUT_LEFT);
	bool right = CheckHitKey(KEY_INPUT_RIGHT);

	// �I�����ڂ̕ύX�i�㉺�L�[�j
	if (up && !prevUp) {
		selectedIndex--;
		if (selectedIndex < 0) selectedIndex = static_cast<int>(debugItems.size()) - 1;
	}
	if (down && !prevDown) {
		selectedIndex++;
		if (selectedIndex >= debugItems.size()) selectedIndex = 0;
	}

	// �I�𒆂̒l�𑝌��i���E�L�[�j
	if (!debugItems.empty()) {
		double& value = *debugItems[selectedIndex].valuePtr;
		if (right && !prevRight) {
			value += 1.0; // ���₷�l
		}
		if (left && !prevLeft) {
			value -= 1.0; // ���炷�l
		}
	}

	// ���͂̑O�t���[���l���X�V
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
	DrawFormatString(x, (int)debugItems.size() * lineHeight, GetColor(255, 255, 255), "ESC�Ŗ߂�");
	
}