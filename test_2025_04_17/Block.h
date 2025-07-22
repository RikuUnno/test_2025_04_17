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
	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument); // ���݂̂̃u���b�N�i�ŏ��̃u���b�N�j

	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement); // ���ړ��̃u���b�N

	//�f�X�g���N�^
	virtual ~Block();

protected:
	// �u���b�N�̉��ړ�
	virtual void MoveBlockDown();

	// �u���b�N�̉��ړ�
	virtual void MoveBlockLateral();

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