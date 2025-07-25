#pragma once
#include "BoxCollider.h"

#include "Block.h"

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

	double m_blockHeight; // ブロックのheight
	double m_space; // ブロックとプレイヤーの間の差

	const char m_ISJUMPING = 0b00001; // ジャンプ中か
	const char m_ISFALLING = 0b00010; // 落下中か
	const char m_ISPUSHTOSPACE = 0b00100; // スペースキーが一度押されたか
	char m_flags; // 上記三項のビット演算用

	const double m_BLOCKDOUWSPEED = 0.7; // ブロックの落下速度
	double m_HumpHeightMax = 200.0; // 最大ジャンプ高さ
	double m_jumpStartY; // ジャンプ開始時のY座標

	double m_jumpVelocity; // 加速率
	double m_fallVelocity; // 加速率

	double m_JumpInitSpeed = 20.0; // 初手のスピード
	double m_JumpGravity = 0.8; // ジャンプの減速

	double m_FallGravity = 0.2; // 降下中の加速
	double m_FallSupeedMax = 50.0; // 加速速度の上限

	double blockHeight; // 当たったブロックの高さ（画面座標）

	BoxCollider* currentColliderPtr = nullptr; // 現在のコライダーのPtr
	BoxCollider* prevColliderPtr = nullptr; // 前のコライダーのPtr

public:
	double* GetHumpHeightMax() { return &m_HumpHeightMax; }
	double* GetJumpInitSpeed() { return &m_JumpInitSpeed; }
	double* GetJumpGravity() { return &m_JumpGravity; }
	double* GetFallGravity() { return &m_FallGravity; }
	double* GetFallSupeedMax() { return &m_FallSupeedMax; }

	ColliderInfo GetPlayerPos() const { return collider; }

private:

	// ジャンプのしてる判定
	void Jumping();

	// 落ちている判定
	void Falling();

	void CollisionEnter(BoxCollider* other) override;
	void CollisionExit(BoxCollider* other) override;

public:
	// コンストラクタ
	Player(PlayerInfo playerArgument);

	// デストラクタ
	virtual ~Player();

	//プレイヤー関係の更新用
	void UpDatePlayer();

	// プレイヤーの描画
	void DrawPlayer() const;

	void SetPosY();

	// プレイヤー状態のリセット
	void Reset(); 

};