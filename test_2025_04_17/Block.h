#pragma once
#include "BoxCollider.h"

struct BlockInfo
{
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
	int m_directionOfMove; // 出てくる方向

public:
	// コンストラクタ
	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument); // 下のみのブロック（最初のブロック）

	Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement); // 横移動のブロック

	//デストラクタ
	virtual ~Block();

protected:
	// ブロックの下移動
	virtual void MoveBlockDown();

	// ブロックの横移動
	virtual void MoveBlockLateral();

public:
	// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
	void DrawBlock() const;

	// ブロックの内部処理（位置の変更等）
	void UpdateBlock();

	// 画面外かの判定
	bool IsOffScreen() const;

	// ブロックの色埋め
	void SetFillBlock();

private:
	void CollisionEnter(BoxCollider* other) override; // 当たり判定

};