#pragma once

#include "GameInfo.h"
#include "Block.h"

// �ŏ��ɏo�Ă���u���b�N�̃N���X ����(����������o�Ă���u���b�N�̂������邩��(���̏ꍇ�͖��O�ύX�K�{)
class FirstBlock : public Block
{
public:
	// ������DrawBox�֐����Q��
	// �����̒l�͍ŏ��Ƀu���b�N�����������ʒu��
	FirstBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag);

	virtual ~FirstBlock();
	
	// �ŏ��̃u���b�N�̍~���p�̃A�b�v�f�[�g�֐�
	void UpdateBlock() override;

};