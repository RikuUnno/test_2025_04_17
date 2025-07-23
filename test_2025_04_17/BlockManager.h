#pragma once
#include "DxLib.h"
#include "Block.h"
#include "Player.h"
#include "BoxCollider.h"
#include <vector>

class BlockManager
{
private:
	std::vector<Block*> blockList; // �u���b�N�̊Ǘ��plist
	std::vector<BoxCollider*> boxColliderList; // ���������R���C�_�[�̃C�x���g�`�F�b�N�p
	double m_createTimer; // �����^�C�}�[
	double m_CreateInteravl; // �C���^�[�o��	
	double m_verticalPos; // ���������c�̈ʒu
	double m_heightRange;
	double m_widthRange; // ��������鉡�͈̔�
	unsigned int m_blockColor; // ��������u���b�N�̐F���i�[

public:
	double& GetCreateInteravl() { return m_CreateInteravl; }
	double& GetHeightRange() { return m_heightRange; }
	double& GetWidthRange() { return m_widthRange; }
	 
public:
	BlockManager(Player* player, unsigned int triangleCr);

	virtual ~BlockManager();

	BlockManager(const BlockManager&) = delete;	// �R�s�[�R���X�g���N�^�֎~
	void operator=(const BlockManager&) = delete;	// ������֎~

	void AddBlocks(Block* newBlock); // �����p�@*�j���̎g�p��delete�Ȃ̂ň����ɂ�new���g��Ȃ��Ƃ߂�����o�O��

	void UpDateBlocks(BoxCollider* player); // �X�V�E�����E�폜�@��{�Ȃ�ł�����

	void CheckHitColliderAll(Player* player); // CheckHitCollider���\�b�h��main�ŉ񂷂��߂̊֐�

	void DrawBlocks() const; // �u���b�N���X�g���g���ĕ`��
private:
	void CheckHitCollider(Block* block, Player* player); // �����蔻��(���)

	void UpDateBlockLateral(BoxCollider* player); // ��{�I�ȉ��ړ��p�̏���

public:
	void Reset(Player* player, unsigned int triangleCr); // ���Z�b�g�p
};
