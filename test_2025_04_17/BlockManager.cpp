#include "BlockManager.h"
#include "DxLib.h"
#include <string>
#include <cmath>

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

void BlockManager::UpDateBlocks(BoxCollider* player)
{
	// ��������
	m_createTimer++; // �t���[�����Ƃɉ��Z

#ifdef _DEBUG
	string timerStr = to_string(m_createTimer);
	DrawString(0, 0, timerStr.c_str(), GetColor(255, 255, 255));
#endif // _DEBUG

	if (m_createTimer >= m_CREATEINTERAVL) // 120�t���[�����Ƃɐ���
	{
		UpDateBlockLateral(player);
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

void BlockManager::UpDateBlockLateral(BoxCollider* player)
{
	ColliderInfo lateralBlockXY = { 0, 0, 0, 0 };
	BlockInfo lateralBlock = { 0, 0 };
	int vx = -1 + 2 * GetRand(1); // -1,1�̒l�������_���Ō��߂�

	int playerY = player->GetColliderInfo().y1;
	int minY = playerY - 100,
		   maxY = playerY;

	m_verticalRange = GetRand(maxY - minY) + minY; // �c�̈ʒu�������_���Őݒ�

	m_blockColor = GetColor(GetRand(255), GetRand(255), GetRand(255)); // �F�������_���Őݒ�

	// ColliderInfo lateralBlockXY = { -100, m_verticalRange , 0, m_verticalRange + 50};
	// BlockInfo lateralBlock = {m_blockColor, FALSE};

	if (vx < 0)
	{
		lateralBlockXY = { WIN_SIZE_X, (double)m_verticalRange, WIN_SIZE_X + 125, (double)m_verticalRange + 50};
		lateralBlock = {m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���
	}
	else if (vx > 0)
	{
		lateralBlockXY = { -125, (double)m_verticalRange, 0, (double)m_verticalRange + 50};
		lateralBlock = {m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���
	}

	AddBlocks(new LateralBlock(lateralBlockXY, lateralBlock, vx)); // �u���b�N�̐���

}

// �u���b�N�̃��X�g���g���ĉ񂵂����̂Ńv���C���[�N���X����������悤�ɂ���
 void BlockManager::CheckHitCollider(Block* block, Player* player)
{
		ColliderInfo p = player->GetColliderInfo();
		ColliderInfo b = block->GetColliderInfo();

#ifdef _DEBUG
		DrawFormatString(0, 45, GetColor(255, 255, 255), "P.y1:%lf P.y2:%lf ", p.y1, p.y2);
#endif // _DEBUG

		//���ꂼ��̒��S�_����̋��������߂�
		double dx = std::fabs(((p.x1 + p.x2) / 2.0) - ((b.x1 + b.x2) / 2.0));
		double dy = std::fabs(((p.y1 + p.y2) / 2.0) - ((b.y1 + b.y2) / 2.0));

		// ���ꂼ��̔����𑫂������������߂�
		double abHW = (((p.x2 - p.x1) / 2.0) + (b.x2 - b.x1) / 2);
		double abHH = (((p.y2 - p.y1) / 2.0) + (b.y2 - b.y1) / 2);

		if (dx < abHW && dy < abHH)
		{
			if (p.y2 <= b.y1 + (b.y2 - b.y1) * 0.5)
			{
				player->SetOnCollisionTrue();
				block->SetOnCollisionTrue(); // �u���b�N�̓����蔻���ύX�i�u���b�N�֌W��false�ɖ߂邱�Ƃ͍��̂Ƃ���Ȃ��j
				
				player->SetPosY(b.y1);  // �`�`�`6/6��������`�`�`

#ifdef _DEBUG
					DrawFormatString(0, 75, GetColor(255, 255, 255), "������");
#endif // _DEBUG
			}
		}
}

 // ��̊֐���main�֐��ŉ񂷂��
 void BlockManager::CheckHitColliderAll(Player* player)
 {
	 for (Block* block : blockList)
	 {
		 if(block != nullptr) CheckHitCollider(block, player);
	 }

 }

 // �`�揈��
 void BlockManager::DrawBlocks() const
 {
	 for (const Block* block : blockList)
	 {
		 if(block != nullptr) block->DrawBlock();
	 }
 }
