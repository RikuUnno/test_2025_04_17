#include "BlockManager.h"

using namespace std;

BlockManager::BlockManager()
{
	m_createTimer = 0; // �����^�C�}�[
	m_verticalRange = 0; // ���������c�͈̔�
	m_blockColor = 0; // ��������u���b�N�̐F���i�[
}

BlockManager::~BlockManager()
{
	// �S�Ẵu���b�N���폜
	for (size_t i = 0; i < blockList.size(); i++)
	{
		delete blockList[i];
	}
	blockList.clear();
}

void BlockManager::AddBlocks(Block* newBlock)
{
	// �u���b�N�̐���
	blockList.push_back(newBlock);
}

void BlockManager::UpDateBlocks()
{
	// ��������
	m_createTimer++; // �t���[�����Ƃɉ��Z

	string timerStr = to_string(m_createTimer);

	DrawString(0, 0, timerStr.c_str(), GetColor(255, 255, 255));

	if (m_createTimer >= m_createInterval) // 120�t���[�����Ƃɐ���
	{
		int leftOrRight = GetRand(1); // 0�`1�̒l�������_���Ō��߂�
		
		if (leftOrRight == LEFT)
		{
			UpDateBlockLateral(LEFT);
		}
		else if (leftOrRight == RIGHT)
		{
			UpDateBlockLateral(RIGHT);
		}

		m_createTimer = 0;
	}
	

	// �j���ƍX�V����

	// �֐��̃|�C���^�Ń��X���Ǘ������č폜�Ȃǂ��ł���悤�ɂ���
	std::vector<Block*>::iterator it = blockList.begin();

	while (it != blockList.end())
	{
		Block* block = *it;
		block->UpdateBlock(); // �u���b�N�̍��W�̍X�V

		if (block->IsOffScreen())
		{
			if (block != nullptr)
			{
				delete block; // �u���b�N�{�̂̍폜
				block = nullptr;
			}
			it = blockList.erase(it); // ���X�g����̍폜
		}
		else
		{
			++it; // ���X�g�̍X�V
		}

	}
}

void BlockManager::UpDateBlockLateral(int leftOrRight)
{
	m_verticalRange = GetRand(250) + 150; // �c�̈ʒu�������_���Őݒ�

	m_blockColor = GetColor(GetRand(205) + 50, GetRand(205) + 50, GetRand(205) + 50); // �F�������_���Őݒ�

	// BlockInfo lateralBlock = {-100, m_verticalRange , 0, m_verticalRange + 50, m_blockColor, FALSE};

	if (leftOrRight == LEFT)
	{
		BlockInfo lateralBlock = { WIN_SIZE_X, m_verticalRange, WIN_SIZE_X + 125, m_verticalRange + 50, m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���

		AddBlocks(new LateralBlock(lateralBlock, LEFT)); // �u���b�N�̐���
	}
	else if (leftOrRight == RIGHT)
	{
		BlockInfo lateralBlock = { -125, m_verticalRange, 0, m_verticalRange + 50, m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���

		AddBlocks(new LateralBlock(lateralBlock, RIGHT)); // �u���b�N�̐���
	}
}
