#include "UnderSpike.h"
#include "GameInfo.h"
#include "DxLib.h"

// ��{�͎O�p�`�`��̊֐��̈��������Ƃɂ��Ă��� xy1�͍��Ӂ@xy2�͉E�Ӂ@xy3�͏�ӂ̈ʒu�����邩��{�͉E�ɑ��₷�̂ō��[�̍��W�Ƃ���
// �Ō�̕ϐ��̂݃X�N���[���̂�������
UnderSpike::UnderSpike(unsigned int color, int fillFlag, int sx)
{ 
	spikeinfo = { 0, 
		WIN_SIZE_Y, 
		WIN_SIZE_X / 12, 
		WIN_SIZE_Y, 
		(WIN_SIZE_X / 12) / 2, 
		WIN_SIZE_Y / 15 * 14, 
		color, fillFlag, sx };

	m_offset = WIN_SIZE_X / 12;
	m_triangleX = 0;
}

void UnderSpike::DrawSpike()
{
	do
	{
		m_triangleX = spikeinfo.x2; // �����̍��v�l�̉��Z

		DrawTriangle(spikeinfo.x1, spikeinfo.y1, spikeinfo.x2, spikeinfo.y2, spikeinfo.x3, spikeinfo.y3, spikeinfo.color, spikeinfo.fillFlag); // �`�揈��

		spikeinfo.x1 = spikeinfo.x2; // ���̍��ӂ̂��̍X�V
		spikeinfo.x2 = spikeinfo.x2 + m_offset; // ���̉E�ӂ̂��̍X�V
		spikeinfo.x3 += m_offset; // ���̏�ӂ̂��̍X�V
	} while (m_triangleX < spikeinfo.sx);
	spikeinfo.x1 -= m_triangleX; // �ŏ��̒l�ɖ߂�
	spikeinfo.x2 -= m_triangleX; // �ŏ��̒l�ɖ߂�
	spikeinfo.x3 -= m_triangleX; // �ŏ��̒l�ɖ߂�
}
