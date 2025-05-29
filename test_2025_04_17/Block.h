#pragma once
#include "GameInfo.h"

#include "BoxCollider.h"

struct BlockInfo
{
	double x1, y1, x2, y2; // �R���X�g���N�^�̈����̒l������
	unsigned int color; // �R���X�g���N�^�̈����̒l������
	int fillFlag; // �R���X�g���N�^�̈����̒l������
};

// �u���b�N�֌W�̐e�N���X
class Block : public BoxCollider
{
protected:
	BlockInfo blockInfo;
	double m_downSpeed; // �����鑬��
	double m_lateralSpeed; // ���ړ��̑���
	int m_fillFlag; // �u���b�N�̓h��Ԃ�

public:
	// �R���X�g���N�^
	Block(BlockInfo blockArgument);

	//�f�X�g���N�^
	virtual ~Block();

protected:
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

public:
	// �u���b�N�����X�g�ŊǗ�������e���������ɏ���
	// �u���b�N�̍폜�͂������ŊǗ�����̂��u���b�N�{�̂̃N���X�ŊǗ�����̂��l���ǂ���
	virtual void UpdateBlock() = 0;
	// ���X�g�����g���čŏ��u���b�N�₱�ꂩ��o�Ă���u���b�N�̈ړ��֌W�̏�����ǉ�����
	// ���̊֐�������������Ɓi���X�g�̍X�V�E�u���b�N�̍폜�j������Ă����悤�ɂ���

	// ��ʊO���̔���
	bool IsOffScreen() const;

};