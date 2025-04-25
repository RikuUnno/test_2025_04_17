#include "DxLib.h"
#include "GameInfo.h"

using namespace std;

//gameinfo
//const int 

// 底辺のとげを作るクラス　
class UnderSpike
{
private:
	int m_offset; // とげの間隔
	int m_triangleX; // とげの長さ
	int m_x1, m_x2, m_x3, m_y1, m_y2, m_y3; // コンストラクタの引数の値を入れる
	unsigned int m_color; // コンストラクタの引数の値を入れる
	int m_fillFrag; // コンストラクタの引数の値を入れる
	int m_Sx; // コンストラクタの引数の値を入れる

public:
	// 基本は三角形描画の関数の引数をもとにしている xy1は左辺　xy2は右辺　xy3は上辺の位置を入れるかつ基本は右に増やすので左端の座標とする
	// 最後の変数のみスクリーンのｘを入れる
	UnderSpike(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color, int fillFrag, int Sx)
	{
		m_x1 = x1;
		m_y1 = y1;
		m_x2 = x2;
		m_y2 = y2;
		m_x3 = x3;
		m_y3 = y3;
		m_color = color;
		m_fillFrag = fillFrag;
		m_Sx = Sx;

		m_offset = x2;
		m_triangleX = 0;
	}

	void DrawSpike()
	{
		do
		{
			m_triangleX = m_x2; // 長さの合計値の加算

			DrawTriangle(m_x1, m_y1, m_x2, m_y2, m_x3, m_y3, m_color, m_fillFrag); // 描画処理

			m_x1 = m_x2; // 次の左辺のｘの更新
			m_x2 = m_x2 + m_offset; // 次の右辺のｘの更新
			m_x3 += m_offset; // 次の上辺のｘの更新
		} while (m_triangleX < m_Sx);
		m_x1 -= m_triangleX; // 最初の値に戻す
		m_x2 -= m_triangleX; // 最初の値に戻す
		m_x3 -= m_triangleX; // 最初の値に戻す
	}
};



// ブロックを管理するクラス（最初のブロック・出てくるブロック）（親クラスにする予定）
// 今は削除の内容のみだがこれから追加していくことになるとおもわれ

// 2025_04_24 進捗ここまで～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～

class BlockManager
{
private:

public:
	BlockManager()
	{

	}

	void BlockDelete()
	{
		// ブロックを消す内容を描く
		// 関数のポインタでリスを管理をして削除などをできるようにする
	}
};

// ブロック関係の親クラス
class Block
{
protected:
	// コンストラクタの引数の値を保管すること変数
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	unsigned int m_color;
	int m_fillFlag;

	int m_downSpeed; // 落ちる速さ
	int m_lateralSpeed; // 横移動の速さ

public:
	// コンストラクタ
	Block(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_color(color), m_fillFlag(fillFlag)
	{
		m_downSpeed = 2; // どのくらいになるかわからないので一応2
		m_lateralSpeed = 2; // どのくらいになるかわからないので一応2
	}

	// ブロックをリストで管理する内容をこっちに書く
	// ブロックの削除はこっちで管理するのかブロック本体のクラスで管理するのか考えどころ
	virtual void UpdateBlock() = 0;
	// リスト等を使って最初ブロックやこれから出てくるブロックの移動関係の処理を追加する
	// この関数を一個だけ入れると（リストの更新・ブロックの削除）をやってくれるようにする

	// ブロックの削除をする
	virtual void DeleteBlock() = 0;
	// 条件式を使ってのブロックの削除（一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

	// ブロックの下移動
	virtual void MoveBlockDown() = 0;
		// 下移動のコードを書く
		// （一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

	// ブロックの横移動
	virtual void MoveBlockLateral() 
	{
		// 横移動のコードを書く(おそらく最初のブロックには使われないものとなる)
		//（一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）
	}

	// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
	virtual void DrawBlock()
	{
		DrawBox(m_x1, m_y1, m_x2, m_y2, m_color, m_fillFlag);
	}

};

// 最初に出てくるブロックのクラス メモ(多分次から出てくるブロックのやつもいれるかも(その場合は名前変更必須)
class FirstBlock : public Block
{
public:
	// 引数はDrawBox関数を参照
	// 引数の値は最初にブロックをおきたい位置で
	FirstBlock(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag)
		: Block(x1, y1, x2, y2, color, fillFlag)
	{
		DrawBlock(); // 描画処理
	}

	// 最初のブロックの降下用のアップデート関数
	void UpdateBlock() override
	{
		// ここに消す判定のメンバ関数を入れる

		MoveBlockDown(); // 下がっていく処理

		DrawBlock(); // 描画処理
	}

	void DeleteBlock() override
	{
		if (m_y1 > WIN_SIZE_Y)
		{

		}
	}

	void MoveBlockDown() override
	{
		m_y1 += m_downSpeed;
		m_y2 += m_downSpeed;
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

	UnderSpike Spike(0, WIN_SIZE_Y, 80, WIN_SIZE_Y, 40, 580, TriangleCr, TRUE, Sx);
	
	FirstBlock FirstBlock(100, 100, 200, 200, TriangleCr, TRUE);

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// ESCを押したら画面が落ちる
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();

		// 三角形を描画
		Spike.DrawSpike();

		FirstBlock.UpdateBlock();

		ScreenFlip();
	}

	DxLib_End(); // DXライブラリ使用の終了処理
}

