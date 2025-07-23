#pragma once
#include "Player.h"
#include "BlockManager.h"
#include <string>

struct DebugItem 
{
	std::string label; // �\������郉�x��
	double* valuePtr; // �l
};

class DebugManager
{
private:
	Player* playerPtr = nullptr; // �v���C���[��ptr
	BlockManager* blockManagerPtr = nullptr; // �u���b�N�}�l�[�W���[��Ptr

	std::vector<DebugItem> debugItems; // �ύX����l��list
	int selectedIndex = 0; // ���Index
	bool prevUp = false, prevDown = false, prevLeft = false, prevRight = false;

private:
	DebugManager() {} // �R���X�g���N�^

	DebugManager(const DebugManager&) = delete;				// �R�s�R���̋֎~
	DebugManager& operator=(const DebugManager&) = delete;	// ����̋֎~

public:
	static DebugManager& GetInstance() {
		static DebugManager instance;
		return instance;
	}

	void Init(Player* player, BlockManager* blockManager);

	void Update();

	void Draw();

};