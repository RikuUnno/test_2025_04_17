#include "GameInfo.h"

#include "UnderSpike.h"
#include "Block.h"
#include "BlockManager.h"
#include "FirstBlock.h"

using namespace std;


// 左移動ブロック
class MoveBlockLeft : public Block
{
public:
	// コンストラクタ
	MoveBlockLeft(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: Block(x1, y1, x2, y2, color, fillFlag)
	{
		DrawBlock();
	}

	// 左移動
	void MoveBlockLateral() override
	{
		blockInfo.x1 -= m_lateralSpeed;
		blockInfo.x2 -= m_lateralSpeed;
	}

	void UpdateBlock() override
	{
		MoveBlockLateral(); // 左移動

		DrawBlock(); // 描画
	}
};

// 右移動ブロック
class MoveBlockRight : public Block
{
public:
	// コンストラクタ
	MoveBlockRight(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: Block(x1, y1, x2, y2, color, fillFlag)
	{
		DrawBlock();
	}

	// 右移動
	void MoveBlockLateral() override
	{
		blockInfo.x1 += m_lateralSpeed;
		blockInfo.x2 += m_lateralSpeed;
	}

	void UpdateBlock() override
	{
		MoveBlockLateral(); // 右移動

		DrawBlock(); // 描画
	}
};


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
	unsigned int TriangleCr = GetColor(255, 255, 0); // 底辺のとげの色をいれる変数（黄色）

	GetScreenState(&Sx, &Sy, &Sc);

	BlockManager BM;

	UnderSpike spike(TriangleCr, TRUE, Sx);
	
	BM.AddBlocks(new FirstBlock(WIN_SIZE_X / 3, 100, WIN_SIZE_X / 3 * 2, 150, TriangleCr, TRUE));

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// ESCを押したら画面が落ちる
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();

		// 三角形を描画
		spike.DrawSpike();

		BM.UpDateBlocks();

		ScreenFlip();
	}

	DxLib_End(); // DXライブラリ使用の終了処理
}

