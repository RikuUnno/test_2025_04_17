#include "BlockManager.h"
#include "DxLib.h"
#include "GameInfo.h"
#include <string>
#include <cmath>

using namespace std;

BlockManager::BlockManager(Player* player, unsigned int triangleCr)
{
	m_createTimer = 0; // �����^�C�}�[
	m_CreateInteravl = 120; // �����C���^�[�o��
	m_verticalPos = 0; // ���������c�͈̔�
	m_blockColor = 0; // ��������u���b�N�̐F���i�[
	boxColliderList.push_back(player); // �ŏ��̈�񂾂��ǉ�
	m_heightRange = 50;
	m_widthRange = 150;
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

	if (m_createTimer >= m_CreateInteravl) // 120�t���[�����Ƃɐ���
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

	int playerY = (int)player->GetColliderInfo().y1;
	int minY = playerY - 100,
		   maxY = playerY;

	m_verticalPos = GetRand(maxY - minY) + minY; // �c�̈ʒu�������_���Őݒ�

	m_blockColor = GetColor(GetRand(255), GetRand(255), GetRand(255)); // �F�������_���Őݒ�

	if (vx < 0)
	{
		lateralBlockXY = { (double)WIN_SIZE_X, (double)m_verticalPos, WIN_SIZE_X + m_widthRange, (double)m_verticalPos + m_heightRange};
		lateralBlock = {m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���
	}
	else if (vx > 0)
	{
		lateralBlockXY = { -m_widthRange, (double)m_verticalPos, 0, (double)m_verticalPos + m_heightRange};
		lateralBlock = {m_blockColor, FALSE }; // ��L�̏������ƂɃu���b�N���̐���
	}

	AddBlocks(new Block(lateralBlockXY, lateralBlock, vx)); // �u���b�N�̐���

}

// �u���b�N�̃��X�g���g���ĉ񂵂����̂Ńv���C���[�N���X����������悤�ɂ���
void BlockManager::CheckHitCollider(Block* block, Player* player)
{
	ColliderInfo p = player->GetColliderInfo();
	ColliderInfo b = block->GetColliderInfo();

	boxColliderList.push_back(block);

	// ���z�̓����蔻����u���b�N��1����ɒu��
	ColliderInfo virtualBlock;
	double height = b.y2 - b.y1;

	virtualBlock.x1 = b.x1 + 10;
	virtualBlock.x2 = b.x2 - 10;
	virtualBlock.y1 = b.y1 - height + 15;  // 1�����
	virtualBlock.y2 = b.y1;           // �u���b�N�̏�ӂ܂�

	// �u�v���C���[�̓����蔻��̏�[�iy1�j�v�����ɉ�����i���𓖂��蔻�肩��O���j
	double playerHeight = p.y2 - p.y1;
	double reduceHead = playerHeight * 0.5f;  // �㔼���𖳌����i���^�񒆂��牺���������蔻��j

	p.y1 += reduceHead;

	// ���S�_����̋���
	double dx = std::fabs(((p.x1 + p.x2) / 2.0) - ((virtualBlock.x1 + virtualBlock.x2) / 2.0));
	double dy = std::fabs(((p.y1 + p.y2) / 2.0) - ((virtualBlock.y1 + virtualBlock.y2) / 2.0));

	// ����T�C�Y
	double abHW = (((p.x2 - p.x1) / 2.0) + (virtualBlock.x2 - virtualBlock.x1) / 2);
	double abHH = (((p.y2 - p.y1) / 2.0) + (virtualBlock.y2 - virtualBlock.y1) / 2);

#ifdef _DEBUG
	// �v���C���[�̓����蔻��F��
	DrawBox(
		(int)(p.x1),
		(int)(p.y1),
		(int)(p.x2),
		(int)(p.y2),
		GetColor(0, 255, 0),
		FALSE  // �h��Ԃ� false = �g���̂�
	);

	// ���z�̏��锻��F��
	DrawBox(
		(int)(virtualBlock.x1),
		(int)(virtualBlock.y1),
		(int)(virtualBlock.x2),
		(int)(virtualBlock.y2),
		GetColor(255, 0, 0),
		FALSE
	);

	DrawLine((int)b.x1 - 30, (int)b.y1, (int)b.x2 + 30, (int)b.y1, GetColor(255, 142, 241));
#endif

	if (dx < abHW && dy < abHH)
	{
		block->AddCurrentHitCollider(player);
		player->AddCurrentHitCollider(block);

#ifdef _DEBUG
		DrawFormatString(0, 75, GetColor(255, 255, 255), "������");
#endif //_DEBUG

	}
}

 // ��̊֐���main�֐��ŉ񂷂��
 void BlockManager::CheckHitColliderAll(Player* player)
 {
	 for (Block* block : blockList)
	 {
		 if(block != nullptr) CheckHitCollider(block, player);
	 }

	 for (BoxCollider* block : boxColliderList)
	 {
		 block->CheckCollisionEvent();
	 }

	 // �v���C���[�ȊO�̃u���b�N��list����폜
	boxColliderList.erase(
		 std::remove_if(boxColliderList.begin(), boxColliderList.end(),
			 [](BoxCollider* collider) {
				 // Player* �ɃL���X�g�ł��Ȃ���΍폜�Ώ�
				 return dynamic_cast<Player*>(collider) == nullptr;
			 }),
		boxColliderList.end()
	 );
 }

 // �`�揈��
 void BlockManager::DrawBlocks() const
 {
	 for (const Block* block : blockList)
	 {
		 if(block != nullptr) block->DrawBlock();
	 }
 }

 void BlockManager::Reset(Player* player, unsigned int triangleCr)
 {
	 // �u���b�N��S�č폜
	 for (Block* block : blockList)
	 {
		 if (block != nullptr)
		 {
			 delete block;
		 }
	 }
	 blockList.clear();

	 // �R���C�_�[���X�g���v���C���[�݂̂�
	 boxColliderList.clear();
	 boxColliderList.push_back(player);

	 // �e��l��������
	 m_createTimer = 0;
	 m_CreateInteravl = 120;
	 m_verticalPos = 0;
	 m_heightRange = 50;
	 m_widthRange = 150;

	 // �����u���b�N��1�ݒu����
	 AddBlocks(new Block({ WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150 }, { triangleCr, TRUE }));
 }