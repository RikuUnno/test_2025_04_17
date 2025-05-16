#pragma once
#include "GameInfo.h"
#include "Block.h"

class BlockManager
{
private:
	std::vector<Block*> blockList; // �u���b�N�̊Ǘ��plist
	int m_createTimer; // �����^�C�}�[
	const int m_createInterval = 120; // ��: 120�t���[������
	int	m_verticalRange; // ���������c�͈̔�

public:
	BlockManager();

	virtual ~BlockManager();

	void AddBlocks(Block* newBlock); // �����p�@*�j���̎g�p��delete�Ȃ̂ň����ɂ�new���g��Ȃ��Ƃ߂�����o�O��

	void UpDateBlocks(); // �X�V�E�����E�폜�@��{�Ȃ�ł�����

	void UpDateBlockLeft(); // ��{�I�ȍ��ړ��p�̏���

	void UpDateBlockRight(); // ��{�I�ȉE�ړ��̏���
};
