#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

class Player : public BoxCollider
{
private:
	PlayerInfo playerInfo;
	const double m_jumpSpeed = 5.0; // 上昇速度
	const double m_gravity = 4.0; // 落下速度
	const double m_jumpHeightMax = 200.0; // 最大ジャンプ高さ
	bool m_isJumping; // ジャンプ中か
	bool m_isFalling; // 落下中か
	bool m_isPushToSpace; // スペースキーが一度押されたか
	double m_jumpStartY; // ジャンプ開始時のY座標

public:
	// コンストラクタ
	Player(PlayerInfo playerArgument);

	// デストラクタ
	virtual ~Player();

	//プレイヤー関係の更新用
	void UpDatePlayer();

	// プレイヤーの描画
	void DrawPlayer() const;

	// ジャンプのしてる判定
	void IsJumping();

	// 落ちている判定
	void IsFalling();


};