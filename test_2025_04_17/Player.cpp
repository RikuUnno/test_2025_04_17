#include "Player.h"
#include <string>

// コンストラクタ
Player::Player(PlayerInfo playerArgument)
	: BoxCollider([&]() // ラムダ式 　BoxColliderの引数に入れるための値の計算
		{
			int sizeXBuf = 0, sizeYBuf = 0; // 画像のサイズを保持する変数（一回きり）
			GetGraphSize(playerArgument.GraphName, &sizeXBuf, &sizeYBuf); // 画像のサイズを取得して格納

			// 親クラスのコンストラクタ引数に格納
			return ColliderInfo{
				playerArgument.x,
				playerArgument.y,
				playerArgument.x + sizeXBuf,
				playerArgument.y + sizeYBuf
			};
		}())
{
	playerInfo = playerArgument; // コンストラクタ引数の情報を保存
	m_isJumping = false; // ジャンプ中か
	m_isFalling = false; // 落下中か
	m_isPushToSpace = false; // スペースキーが一度押されたか
	m_jumpStartY = 0.0; // ジャンプ開始時のY座標
}

// デストラクタ
Player::~Player()
{

}

//プレイヤー関係の更新用
void Player::UpDatePlayer()
{

#ifdef _DEBUG
	std::string timerStr = std::to_string(playerInfo.y);
	DrawString(0, 15, timerStr.c_str(), GetColor(255, 255, 255));
#endif // _DEBUG


	if (!CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isPushToSpace = false; // 一度押したら離すまで再入力されない
	}

	// スペースを押したらジャンプ
	if (!m_isJumping && !m_isFalling && CheckHitKey(KEY_INPUT_SPACE) && !m_isPushToSpace)
	{
		m_isJumping = true; // ジャンプしてる
		m_isPushToSpace = true; // 一度押したら離すまで再入力されない
		m_jumpStartY = playerInfo.y;
	}

	if (m_isJumping)
	{
		IsJumping();
	}

	if (m_isFalling)
	{
		IsFalling();
	}


	DrawPlayer(); // プレイヤーの描画
}

// プレイヤーの描画
void Player::DrawPlayer() const
{
	DrawGraph((int)playerInfo.x, (int)playerInfo.y, playerInfo.GraphName, playerInfo.TransFlag);
}

// ジャンプのしてる判定
void Player::IsJumping()
{
	playerInfo.y -= m_jumpSpeed;
	if (playerInfo.y <= m_jumpStartY - m_jumpHeightMax || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isJumping = false; // ジャンプしていない
		m_isFalling = true; // 空中
	}
}

// 落ちてる判定
void Player::IsFalling()
{
	playerInfo.y += m_gravity;
	if (playerInfo.y >= 300) // ここに当たり判定系の処理を入れる（落ちる高さ）
	{
		m_isFalling = false; // 何かしらの上
	}
}