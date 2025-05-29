#pragma once

#include "GameInfo.h"

struct SpikInfo
{
	int x1, y1, x2, y2, x3, y3; // �R���X�g���N�^�̈����̒l������
	unsigned int color; // �R���X�g���N�^�̈����̒l������
	int fillFlag; // �R���X�g���N�^�̈����̒l������
	int sx; // �R���X�g���N�^�̈����̒l������
};

// ��ӂ̂Ƃ������N���X�@
class UnderSpike
{
private:
	int m_offset; // �Ƃ��̊Ԋu
	int m_triangleX; // �Ƃ��̒���
	SpikInfo spikeinfo; // �Ƃ��̈ʒu���̏��

public:
	// ��{�͎O�p�`�`��̊֐��̈��������Ƃɂ��Ă��� xy1�͍��Ӂ@xy2�͉E�Ӂ@xy3�͏�ӂ̈ʒu�����邩��{�͉E�ɑ��₷�̂ō��[�̍��W�Ƃ���
	// �Ō�̕ϐ��̂݃X�N���[���̂�������
	UnderSpike(unsigned int color, int fillFlag, int sx);

	void DrawSpike();
};