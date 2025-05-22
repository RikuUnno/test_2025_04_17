#pragma once
#include "DxLib.h"
#include <vector>
#include <string>
#include <time.h>

#define LEFT 0
#define RIGHT 1

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
	double x1, y1, x2, y2; // �R���X�g���N�^�̈����̒l������
	unsigned int color; // �R���X�g���N�^�̈����̒l������
	int fillFlag; // �R���X�g���N�^�̈����̒l������
};