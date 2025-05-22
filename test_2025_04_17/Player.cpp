#include "Player.h"

// コンストラクタ
Player::Player(PlayerInfo playerArgument)
	: BoxCollider(playerArgument.x, )
{

}

// デストラクタ
Player::~Player()
{

}

//プレイヤー関係の更新用
void Player::UpDatePlayer()
{

}

// プレイヤーの描画
void Player::DrawPlayer()
{
	LoadGraphScreen();
}