#pragma once
#include "DxLib.h"
#include <vector>

// �E�B���h�E�T�C�Y
const int WIN_SIZE_X = 480;
const int WIN_SIZE_Y = 640;

struct SpikInfo
{
	int x1, y1, x2, y2, x3, y3; // �R���X�g���N�^�̈����̒l������
	unsigned int color; // �R���X�g���N�^�̈����̒l������
	int fillFlag; // �R���X�g���N�^�̈����̒l������
	int Sx; // �R���X�g���N�^�̈����̒l������
};

struct BlockInfo
{
	float x1, y1, x2, y2; // �R���X�g���N�^�̈����̒l������
	unsigned int color; // �R���X�g���N�^�̈����̒l������
	int fillFlag; // �R���X�g���N�^�̈����̒l������
};