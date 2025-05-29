#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

struct PlayerInfo
{
	double x, y; // ロードした画像を描画する矩形の左上頂点の座標
	int GraphName; // 画像ハンドラー
	int TransFlag; // 画像の透明度を有効にするかどうか
};

class Player : public BoxCollider
{
private:
	PlayerInfo playerInfo;
	const double m_JUMPSPEED = 5.0; // 上昇速度
	const double m_GRAVITY = 4.0; // 落下速度
	const double m_HUMPHEIGHTMAX = 200.0; // 最大ジャンプ高さ
	const char m_ISJUMPING = 0b00001; // ジャンプ中か
	const char m_ISFALLING = 0b00010; // 落下中か
	const char m_ISPUSHTOSPACE = 0b00100; // スペースキーが一度押されたか
	char m_flags; // 上記三項のビット演算用
	double m_jumpStartY; // ジャンプ開始時のY座標

private:

	// ジャンプのしてる判定
	void Jumping();

	// 落ちている判定
	void Falling();

public:
	// コンストラクタ
	Player(PlayerInfo playerArgument);

	// デストラクタ
	virtual ~Player();

	//プレイヤー関係の更新用
	void UpDatePlayer();

	// プレイヤーの描画
	void DrawPlayer() const;
};