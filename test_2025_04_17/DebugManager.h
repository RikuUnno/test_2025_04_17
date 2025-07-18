#pragma once
#include "Player.h"
#include "BlockManager.h"

class DebugManager
{
private:
	Player* playerPtr = nullptr; 
	BlockManager* blockManagerPtr = nullptr;

private:
	DebugManager(){} // �R���X�g���N�^

	DebugManager(const DebugManager&) = delete;				// �R�s�R���̋֎~
	DebugManager& operator=(const DebugManager&) = delete;	// ����̋֎~
	
public:
	static DebugManager& GetInstance() {
		static DebugManager instance;
		return instance;
	}

	void SetPlayer(Player* player) { // PlayerClass�̃Z�b�g
		playerPtr = player;
	}

	void SetBlockManager(BlockManager* blockManager) { // BlockManager�̃Z�b�g
		blockManagerPtr = blockManager;
	}





}
