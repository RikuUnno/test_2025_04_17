#include "Block.h"

	// �R���X�g���N�^
Block::Block(BlockInfo block)
{
	blockInfo = block;

	m_downSpeed = 0.7f; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ2
	m_lateralSpeed = 0.7f; // �ǂ̂��炢�ɂȂ邩�킩��Ȃ��̂ňꉞ2
}

//�f�X�g���N�^
Block::~Block()
{
	//����
}

// �u���b�N�̉��ړ�
void Block::MoveBlockDown()
{
	blockInfo.y1 += m_downSpeed;
	blockInfo.y2 += m_downSpeed;
}

// �u���b�N�̉��ړ�
void Block::MoveBlockLateral()
{
	// �ŏ��̃u���b�N�������Ă��܂��̂ł����ɂ͏����Ȃ�
	// memo FirstBlockClass�Ɏ����������Ȃ��Ƃ����Ȃ��Ȃ�̂łƂ肠�������z�֐��i�ʂ̓���������u���b�N�����Ƃ��͕ς����ق������������j
}

// �`��݂̂����� (�����Ɋւ��Ă� "DrawBox"�@�̕����Q��)
void Block::DrawBlock()
{
	DrawBox((int)blockInfo.x1, (int)blockInfo.y1, (int)blockInfo.x2, (int)blockInfo.y2, blockInfo.color, blockInfo.fillFlag);
}

// ��ʊO���̔���
bool Block::IsOffScreen() const
{
	// ��ӂ���ʉ���艺�̏ꍇ�@�E�ӂ���ʍ��[�T�O���W��菭�Ȃ��Ƃ��@���ӂ���ʉE�{�T�O���W��葽���Ƃ��ɏ�����
	// ���E�{�T�O�ɂ��Ă���̂͐������Ă��������Ȃ��悤�ɂ��邽�߁i���㑝�₷�����j�@
	return blockInfo.y1 > WIN_SIZE_Y || blockInfo.x2 < -200 || blockInfo.x1 > WIN_SIZE_X + 200;
}

