#pragma once

#include "GameInfo.h"
#include "Block.h"

// �ŏ��ɏo�Ă���u���b�N�̃N���X ����(����������o�Ă���u���b�N�̂������邩��(���̏ꍇ�͖��O�ύX�K�{)
class FirstBlock : public Block
{
public:
	// ������DrawBox�֐����Q��
	// �����̒l�͍ŏ��Ƀu���b�N�����������ʒu��
	FirstBlock(BlockInfo blockArgument);

	virtual ~FirstBlock();
	
private:
	// �ŏ��̃u���b�N�̍~���p�̃A�b�v�f�[�g�֐�
	void UpdateBlock() override;

};