#pragma once
#include "DxLib.h"

#include <vector>

#define LEFT 0
#define RIGHT 1

// ウィンドウサイズ
const int WIN_SIZE_X = 480;
const int WIN_SIZE_Y = 640;

struct SpikInfo
{
	int x1, y1, x2, y2, x3, y3; // コンストラクタの引数の値を入れる
	unsigned int color; // コンストラクタの引数の値を入れる
	int fillFlag; // コンストラクタの引数の値を入れる
	int Sx; // コンストラクタの引数の値を入れる
};

struct BlockInfo
{
	double x1, y1, x2, y2; // コンストラクタの引数の値を入れる
	unsigned int color; // コンストラクタの引数の値を入れる
	int fillFlag; // コンストラクタの引数の値を入れる
};

struct PlayerInfo
{
	double x, y; // ロードした画像を描画する矩形の左上頂点の座標
	int GraphName; // 画像ハンドラー
	int TransFlag; // 画像の透明度を有効にするかどうか
};

struct ColliderInfo
{
	double x1, y1, x2, y2;
};
