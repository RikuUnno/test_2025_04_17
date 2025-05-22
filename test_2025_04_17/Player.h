#pragma once

#include "GameInfo.h"
#include "BoxCollider.h"

class Player : public BoxCollider
{
private:


public:
	// コンストラクタ
	Player(PlayerInfo);

	// デストラクタ
	virtual ~Player();

	//プレイヤー関係の更新用
	void UpDatePlayer();

	// プレイヤーの描画
	void DrawPlayer();

	// プレイヤーの移動


};