#include "FirstBlock.h"

// ������DrawBox�֐����Q��
// �����̒l�͍ŏ��Ƀu���b�N�����������ʒu��
FirstBlock::FirstBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: Block(x1, y1, x2, y2, color, fillFlag)
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
