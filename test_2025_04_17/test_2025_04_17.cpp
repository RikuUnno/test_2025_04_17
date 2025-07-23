#include "GameInfo.h"

#include "UnderSpike.h"
#include "Block.h"
#include "BlockManager.h"
#include "Player.h"
#include "BoxCollider.h"
#include "DebugManager.h"
#include "GameManager.h"

#include <time.h>

using namespace std;

enum class GameScene
{
	TITLE,
	PLAY,
	RESULT,
	DEBUG
};

static GameScene currentScene = GameScene::TITLE;

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

	bool isMenuOpen = false;
	int menuSelection = 0; // 0: 続ける, 1: タイトルへ

	GetScreenState(&sx, &sy, &sc);// 現在のスクリーンのx,y,colorを取得

	int playerGraph = LoadGraph("idolFront.png"); // プレイヤーの画像ハンドル

	UnderSpike spike(triangleCr, TRUE, sx);

	Player player(PlayerInfo({ WIN_SIZE_X / 2, WIN_SIZE_Y / 20, playerGraph, TRUE}));

	BlockManager bm(&player, triangleCr);

	ColliderInfo blockXY = { 0,0,0,0 }; // 生成用
	BlockInfo block = { 0,0 }; // 生成用
	
	DebugManager::GetInstance().Init(&player, &bm);

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_FRONT);

	// ESCを押したら画面が落ちる
	while (ProcessMessage() == 0)
	{
		clsDx();
		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_H)) currentScene = GameScene::DEBUG;

		switch (currentScene) {
		case GameScene::TITLE:
			DrawFormatString(WIN_SIZE_X / 2 - 70, WIN_SIZE_Y / 3, GetColor(255, 255, 255), "上に上ってゲー");
			DrawFormatString(WIN_SIZE_X / 2 - 70, WIN_SIZE_Y / 3 * 2 , GetColor(255, 255, 255), "Sキーでスタート");
			
			if (CheckHitKey(KEY_INPUT_S)) {
				player.Reset();
				bm.Reset(&player, triangleCr);
				currentScene = GameScene::PLAY;
			}
			break;

		case GameScene::PLAY:

			if (CheckHitKey(KEY_INPUT_M)) {
				isMenuOpen = true;
			}

			if (isMenuOpen) {
				int centerX = WIN_SIZE_X / 2;
				int centerY = WIN_SIZE_Y / 2;

				DrawBox(centerX - 100, centerY - 60, centerX + 100, centerY + 60, GetColor(0, 0, 0), TRUE); // メニュー背景
				DrawString(centerX - 30, centerY - 40, "メニュー", GetColor(255, 255, 255));
				DrawString(centerX - 40, centerY - 10, "1キー: 続ける", GetColor(255, 255, 255));
				DrawString(centerX - 50, centerY + 20, "2キー: タイトルへ", GetColor(255, 255, 255));

				if (CheckHitKey(KEY_INPUT_1)) {
					isMenuOpen = false;
				}
				if (CheckHitKey(KEY_INPUT_2)) {
					isMenuOpen = false;
					currentScene = GameScene::TITLE;
				}

				break; // メニューが開いてる間は下の処理は行わない
			}

			// --- 通常のゲーム進行処理 ---
			bm.CheckHitColliderAll(&player);
			bm.UpDateBlocks(&player);
			player.UpDatePlayer();

			bm.DrawBlocks();
			player.DrawPlayer();
			spike.DrawSpike();

			DrawFormatString(WIN_SIZE_X / 15, WIN_SIZE_Y / 17, GetColor(255, 255, 255), "生き残れた数 %d個", GameManager::GetInstance().GetPoint());

			if (player.GetColliderInfo().y2 >= spike.GetSpikeTopY()) currentScene = GameScene::RESULT;
			break;

		case GameScene::RESULT:
			DrawFormatString(WIN_SIZE_X / 2 - 60, WIN_SIZE_Y / 3, GetColor(255, 0, 0), "GAME OVER");
			DrawFormatString(WIN_SIZE_X / 2 - 60, WIN_SIZE_Y / 3 + 40, GetColor(255, 255, 255), "生き残れた数 %d個", GameManager::GetInstance().GetPoint());
			DrawFormatString(WIN_SIZE_X / 2 - 80, WIN_SIZE_Y / 2, GetColor(255, 255, 255), "1キー: 再挑戦");
			DrawFormatString(WIN_SIZE_X / 2 - 80, WIN_SIZE_Y / 2 + 30, GetColor(255, 255, 255), "2キー: タイトル");

			// 再挑戦（ゲーム再スタート）
			if (CheckHitKey(KEY_INPUT_1)) {
				// プレイヤーとブロックの状態をリセット
				player.Reset();
				bm.Reset(&player, triangleCr);

				currentScene = GameScene::PLAY;
			}

			// タイトルへ戻る
			if (CheckHitKey(KEY_INPUT_2)) {
				currentScene = GameScene::TITLE;
			}
		break;

		case GameScene::DEBUG:
			DebugManager::GetInstance().Update();
			DebugManager::GetInstance().Draw();
			if(CheckHitKey(KEY_INPUT_ESCAPE)) currentScene = GameScene::PLAY;
			break;
		}

		ScreenFlip();
	}

	DxLib_End(); // DXライブラリ使用の終了処理

	return 0;
}

