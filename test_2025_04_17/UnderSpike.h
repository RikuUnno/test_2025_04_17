#pragma once

#include "GameInfo.h"

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
	UnderSpike(unsigned int color, int fillFlag, int Sx);

	void DrawSpike();
};