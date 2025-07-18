#pragma once
#include "BoxCollider.h"

struct BlockInfo
{
	unsigned int color; // �u���b�N�̐F
	int fillFlag; // ���߂邩�ǂ���
};

// �u���b�N�֌W�̐e�N���X
class Block : public BoxCollider
{
protected:
	BlockInfo blockInfo;
	double m_downSpeed; // �����鑬��
	double m_lateralSpeed; // ���ړ��̑���
	int m_fillFlag; // �u���b�N�̓h��Ԃ�
	int m_directionOfMove; // �o�Ă������

public:
	// �R���X�g���N�^
	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument);

	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement);

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

public:
	// �`��݂̂����� (�����Ɋւ��Ă� "DrawBox"�@�̕����Q��)
	void DrawBlock() const;

	// �u���b�N�̓��������i�ʒu�̕ύX���j
	void UpdateBlock();

	// ��ʊO���̔���
	bool IsOffScreen() const;

	// �u���b�N�̐F����
	void SetFillBlock();

private:
	void CollisionEnter(BoxCollider* other) override; // �����蔻��

};