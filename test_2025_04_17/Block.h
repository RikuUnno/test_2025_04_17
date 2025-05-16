#pragma once
#include "GameInfo.h"

// �u���b�N�֌W�̐e�N���X
class Block
{
protected:
	BlockInfo blockInfo;
	double m_downSpeed; // �����鑬��
	double m_lateralSpeed; // ���ړ��̑���

public:
	// �R���X�g���N�^
	Block(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag);

	//�f�X�g���N�^
	virtual ~Block();

	// �u���b�N�����X�g�ŊǗ�������e���������ɏ���
	// �u���b�N�̍폜�͂������ŊǗ�����̂��u���b�N�{�̂̃N���X�ŊǗ�����̂��l���ǂ���
	virtual void UpdateBlock() = 0;
	// ���X�g�����g���čŏ��u���b�N�₱�ꂩ��o�Ă���u���b�N�̈ړ��֌W�̏�����ǉ�����
	// ���̊֐�������������Ɓi���X�g�̍X�V�E�u���b�N�̍폜�j������Ă����悤�ɂ���

	// �u���b�N�̉��ړ�
	virtual void MoveBlockDown();
	// ���ړ��̃R�[�h������
	// �i��t���[�����ƂɈ��Ă΂��悤�ɂ���̂ł���ȉۂ͈�t���[�����ɍs�������������j

	// �u���b�N�̉��ړ�
	virtual void MoveBlockLateral();
	// ���ړ��̃R�[�h������(�����炭�ŏ��̃u���b�N�ɂ͎g���Ȃ����̂ƂȂ�)
	//�i��t���[�����ƂɈ��Ă΂��悤�ɂ���̂ł���ȉۂ͈�t���[�����ɍs�������������j

	// �`��݂̂����� (�����Ɋւ��Ă� "DrawBox"�@�̕����Q��)
	virtual void DrawBlock();

	// ��ʊO���̔���
	bool IsOffScreen() const;

};