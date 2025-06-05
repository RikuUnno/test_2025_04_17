#pragma once
#include "BoxCollider.h"

struct BlockInfo
{
	// double x1, y1, x2, y2; // ブロックの位置情報
	unsigned int color; // ブロックの色
	int fillFlag; // 埋めるかどうか
};

// ブロック関係の親クラス
class Block : public BoxCollider
{
protected:
	BlockInfo blockInfo;
	double m_downSpeed; // 落ちる速さ
	double m_lateralSpeed; // 横移動の速さ
	int m_fillFlag; // ブロックの塗りつぶし

public:
	// コンストラクタ
	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument);

	//デストラクタ
	virtual ~Block();

protected:
	// ブロックの下移動
	virtual void MoveBlockDown();
	// 下移動のコードを書く
	// （一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

	// ブロックの横移動
	virtual void MoveBlockLateral();
	// 横移動のコードを書く(おそらく最初のブロックには使われないものとなる)
	//（一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

public:
	// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
	virtual void DrawBlock() const;

	// ブロックの内部処理（位置の変更等）
	virtual void UpdateBlock() = 0;

	// 画面外かの判定
	bool IsOffScreen() const;

	// ブロックの色埋め
	void SetFillBlock();
};