#pragma once
#include "GameInfo.h"
#include "Block.h"
#include "LateralBlock.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // �u���b�N�̊Ǘ��plist
	int m_createTimer; // �����^�C�}�[
	const int m_createInterval = 300; // ��: 300�t���[������
	int	m_verticalRange; // ���������c�͈̔�
	unsigned int m_blockColor; // ��������u���b�N�̐F���i�[

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // �����p�@*�j���̎g�p��delete�Ȃ̂ň����ɂ�new���g��Ȃ��Ƃ߂�����o�O��

	void UpDateBlocks(); // �X�V�E�����E�폜�@��{�Ȃ�ł�����

	void UpDateBlockLateral(int leftOrRight); // ��{�I�ȉ��ړ��p�̏���
};
