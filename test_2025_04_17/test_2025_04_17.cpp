#include "GameInfo.h"

#include "UnderSpike.h"
#include "Block.h"
#include "BlockManager.h"
#include "Player.h"
#include "BoxCollider.h"

#include <time.h>

using namespace std;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウインドウモードで起動

	SetGraphMode(WIN_SIZE_X, WIN_SIZE_Y, 32); // 画面サイズのセット

	SetWindowText("上に登ってゲー");

	if (DxLib_Init() == -1) // DXライブラリの初期化
	{
		return -1; // エラーが起きたら直ちに終了
	}

	SRand((unsigned int)time(NULL));

	int sx, sy, sc; // 現在のスクリーンのx,y,colorを入れる変数
	const unsigned int triangleCr = GetColor(GetRand(205) + 50, GetRand(205) + 50, GetRand(205) + 50); // 底辺のとげの色をいれる変数（ランダム）

	GetScreenState(&sx, &sy, &sc);// 現在のスクリーンのx,y,colorを取得

	// ～～～～～～～～　
	// ここに画像読み込みをforで回して行う
	int playerGraph = LoadGraph("idolFront.png");
	// ～～～～～～～～

	UnderSpike spike(triangleCr, TRUE, sx);

	Player player(PlayerInfo({ WIN_SIZE_X / 2, WIN_SIZE_Y / 20, playerGraph, TRUE}));

	BlockManager bm(&player, triangleCr);

	ColliderInfo blockXY = { 0,0,0,0 }; // 生成用
	BlockInfo block = { 0,0 }; // 生成用
	bm.AddBlocks(new Block(blockXY = { WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150 }, block = { triangleCr, TRUE }));

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_FRONT);

	// ESCを押したら画面が落ちる
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();

		bm.CheckHitColliderAll(&player); // 当たり判定

		bm.UpDateBlocks(&player); // ブロックの内部処理

		player.UpDatePlayer(); // プレイヤーの内部処理

		// ～～～描画～～～　処理の手順と描画で入れ違うことがあったので分離

		spike.DrawSpike(); // スパイクを描画

		bm.DrawBlocks(); // ブロックの描画

		player.DrawPlayer(); // プレイヤーの描画
		
		DrawFormatString(0, 150, GetColor(255, 255, 255), "Jumping: %s", player.GetOnCollision() ? "True" : "False");

		ScreenFlip();
	}

	DxLib_End(); // DXライブラリ使用の終了処理

	return 0;
}

