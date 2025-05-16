#include "GameInfo.h"

#include "UnderSpike.h"
#include "Block.h"
#include "BlockManager.h"
#include "FirstBlock.h"
#include "LateralBlock.h"

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
	
	int Sx, Sy, Sc; // 現在のスクリーンのx,y,colorを入れる変数
	const unsigned int TriangleCr = GetColor(255, 255, 0); // 底辺のとげの色をいれる変数（黄色）

	GetScreenState(&Sx, &Sy, &Sc);

	BlockManager bm;

	UnderSpike spike(TriangleCr, TRUE, Sx);
	
	bm.AddBlocks(new FirstBlock(WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150, TriangleCr, TRUE));

	// デバック用
	bm.AddBlocks(new LateralBlock(WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150, TriangleCr, FALSE, RIGHT));

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// ESCを押したら画面が落ちる
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();

		// 三角形を描画
		spike.DrawSpike();

		bm.UpDateBlocks();

		ScreenFlip();
	}

	DxLib_End(); // DXライブラリ使用の終了処理
}

