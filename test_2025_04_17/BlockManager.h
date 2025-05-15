#pragma once
#include "GameInfo.h"
#include "Block.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // �u���b�N�̊Ǘ��plist
	int createTimer; // �����^�C�}�[
	const int createInterval = 120; // ��: 120�t���[������

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // �����p�@*�j���̎g�p��delete�Ȃ̂ň����ɂ�new���g��Ȃ��Ƃ߂�����o�O��

	void UpDateBlocks(); // �X�V�E�����E�폜�@��{�Ȃ�ł�����
};
