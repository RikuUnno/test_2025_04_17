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
{ // ～～～ここからコンストラクタの中身～～～↓
	playerInfo = playerArgument; // コンストラクタ引数の情報を保存
	m_flags = 0; // (0b00000000)
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


	if (!CheckHitKey(KEY_INPUT_SPACE)) // スペースキーを押していたら
	{
		m_flags &= ~m_ISPUSHTOSPACE; // 一度押したら離すまで再入力されない
	}

	// スペースを押したらジャンプ
	if (!(m_flags & m_ISJUMPING) && !(m_flags & m_ISFALLING) 
		&& !(m_flags & m_ISPUSHTOSPACE) && CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags |= m_ISJUMPING; // ジャンプしてる
		m_flags |= m_ISPUSHTOSPACE; // 一度押したら離すまで再入力されない
		m_jumpStartY = playerInfo.y;
	}

	if (m_flags & m_ISJUMPING) // 飛んでいたら
	{
		Jumping();
	}

	if (m_flags & m_ISFALLING) // 落ちていたら
	{
		Falling();
	}

	DrawPlayer(); // プレイヤーの描画
}

// プレイヤーの描画
void Player::DrawPlayer() const
{
	DrawGraph((int)playerInfo.x, (int)playerInfo.y, playerInfo.GraphName, playerInfo.TransFlag);
}

// ジャンプのしてる判定
void Player::Jumping()
{
	playerInfo.y -= m_JUMPSPEED;
	if (playerInfo.y <= m_jumpStartY - m_HUMPHEIGHTMAX || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags &= ~m_ISJUMPING; // ジャンプしていない
		m_flags |= m_ISFALLING; // 空中
	}
}

// 落ちてる判定
void Player::Falling()
{
	playerInfo.y += m_GRAVITY;
	if (playerInfo.y >= 300) // ここに当たり判定系の処理を入れる（落ちる高さ）
	{
		m_flags &= ~m_ISFALLING; // 何かしらの上
	}
}