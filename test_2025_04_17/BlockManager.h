#pragma once
#include "DxLib.h"
#include "Block.h"
#include "Player.h"
#include "LateralBlock.h"
#include <vector>

class BlockManager
{
private:
	std::vector<Block*> blockList; // �u���b�N�̊Ǘ��plist
	int m_createTimer; // �����^�C�}�[
	const int m_CREATEINTERAVL = 120; // ��: 120�t���[������
	double	m_verticalRange; // ���������c�͈̔�
	unsigned int m_blockColor; // ��������u���b�N�̐F���i�[

public:
	BlockManager();

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
};
