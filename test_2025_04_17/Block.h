#pragma once
#include "GameInfo.h"

// ブロック関係の親クラス
class Block
{
protected:
	BlockInfo blockInfo;
	double m_downSpeed; // 落ちる速さ
	double m_lateralSpeed; // 横移動の速さ

public:
	// コンストラクタ
	Block(int x1, int y1, int x2, int y2, unsigned int color, int fillFlag);

	//デストラクタ
	virtual ~Block();

	// ブロックをリストで管理する内容をこっちに書く
	// ブロックの削除はこっちで管理するのかブロック本体のクラスで管理するのか考えどころ
	virtual void UpdateBlock() = 0;
	// リスト等を使って最初ブロックやこれから出てくるブロックの移動関係の処理を追加する
	// この関数を一個だけ入れると（リストの更新・ブロックの削除）をやってくれるようにする

	// ブロックの下移動
	virtual void MoveBlockDown();
	// 下移動のコードを書く
	// （一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

	// ブロックの横移動
	virtual void MoveBlockLateral();
	// 横移動のコードを書く(おそらく最初のブロックには使われないものとなる)
	//（一フレームごとに一回呼ばれるようにするのでこんな課は一フレーム毎に行う処理を書く）

	// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
	virtual void DrawBlock();

	// 画面外かの判定
	bool IsOffScreen() const;

};