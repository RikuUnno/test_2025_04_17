#include "FirstBlock.h"

// ������DrawBox�֐����Q��
// �����̒l�͍ŏ��Ƀu���b�N�����������ʒu��
FirstBlock::FirstBlock(BlockInfo block)
		: Block(block)
{
	DrawBlock(); // �`�揈��
}

FirstBlock::~FirstBlock()
{}

// �ŏ��̃u���b�N�̍~���p�̃A�b�v�f�[�g�֐�
void FirstBlock::UpdateBlock()
{
	// �����ɏ�������̃����o�֐�������

	MoveBlockDown(); // �������Ă�������

	DrawBlock(); // �`�揈��
}
