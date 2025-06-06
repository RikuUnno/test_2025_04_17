#include "Player.h"
#include "DxLib.h"
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
	m_jumpVelocity = 0.0; // 加速率
	m_fallVelocity = 0.0; // 加速率

	m_blockHeight = 0.0; // ブロックのheight
	m_space = 0.0; // ブロックとプレイヤーの間の差
}

// デストラクタ
Player::~Player()
{

}

//プレイヤー関係の更新用
void Player::UpDatePlayer()
{

	if (!CheckHitKey(KEY_INPUT_SPACE)) // スペースキーを押していたら
	{
		m_flags &= ~m_ISPUSHTOSPACE; // 一度押したら離すまで再入力されない
	}

	// スペースを押したらジャンプ
	if (!(m_flags & m_ISJUMPING) && !(m_flags & m_ISFALLING) 
		&& !(m_flags & m_ISPUSHTOSPACE) && CheckHitKey(KEY_INPUT_SPACE) )
	{
		m_flags |= m_ISJUMPING; // ジャンプしてる
		m_flags |= m_ISPUSHTOSPACE; // 一度押したら離すまで再入力されない
		m_jumpStartY = collider.y1;
		m_jumpVelocity = m_JUMP_INIT_SPEED; // 初速セット
		SetOnCollisionFalse();
	}

	if (m_flags & m_ISJUMPING) // 飛んでいたら
	{
		Jumping();

	}

	if (!(m_flags & m_ISJUMPING)) // 落ちていたら
	{
		Falling();
	}

	if (m_onCollision)
	{
		m_flags &= ~m_ISJUMPING; // ジャンプをしていない
		m_flags &= ~m_ISFALLING; // 空中でもない
		
		OnCollision();
	}
}

// プレイヤーの描画
void Player::DrawPlayer() const
{
	DrawGraph((int)collider.x1, (int)collider.y1, playerInfo.GraphName, playerInfo.TransFlag);
}

// ジャンプのしてる判定
void Player::Jumping()
{
#ifdef _DEBUG
	DrawFormatString(0, 90, GetColor(255, 255, 255), "Jumping");
#endif // _DEBUG

	collider.y1 -= m_jumpVelocity, 
	collider.y2 -= m_jumpVelocity; // プレイヤーのｙ軸の変更
	m_jumpVelocity -= m_JUMP_GRAVITY; // 毎フレーム減速

	if (collider.y1 <= m_jumpStartY - m_HUMPHEIGHTMAX || !CheckHitKey(KEY_INPUT_SPACE))
	{
		m_flags &= ~m_ISJUMPING; // ジャンプしていない
		m_flags |= m_ISFALLING; // 落ちている
		m_fallVelocity = 0.0;
	}
}

// 落ちてる判定
void Player::Falling()
{
#ifdef _DEBUG
	DrawFormatString(0, 105, GetColor(255, 255, 255), "Falling");
#endif // _DEBUG

	if (m_onCollision && !(m_flags & m_ISJUMPING)) // ここに当たり判定系の処理を入れる（落ちる高さ）
	{
		m_flags &= ~m_ISFALLING; // 何かしらの上
		m_fallVelocity = 0.0; // 落下停止（なにがしの上）
	}
	else
	{
		m_fallVelocity += m_FALL_GRAVITY;
		if (m_fallVelocity > m_FALL_SUPEED_MAX) m_fallVelocity = m_FALL_SUPEED_MAX; // 一定の速度になったら加速をやめる
		
		collider.y1 += m_fallVelocity,
		collider.y2 += m_fallVelocity; // プレイヤーのｙ軸の変更
	}
}

// 当たり判定の処理
void Player::OnCollision()
{
	collider.y1 += m_BLOCKDOUWSPEED, collider.y2 += m_BLOCKDOUWSPEED; // ブロックと同じ速度
}

void Player::SetPosY(double blockHeight)
{
	m_blockHeight = blockHeight;
	m_space = blockHeight - collider.y2; // ブロックの上辺とプレイヤーの下辺のスペースを取る

	collider.y1 += m_space;
	collider.y2 = blockHeight;
}

