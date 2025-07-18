#include "Block.h"
#include "DxLib.h"
#include "GameInfo.h"
#include "BlockManager.h"

	// コンストラクタ
Block::Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument)
	: BoxCollider({ blockArgumentXY})
{
	blockInfo = blockArgument;

	m_downSpeed = 0.7; // どのくらいになるかわからないので一応0.7f
	m_lateralSpeed = 3.5; // どのくらいになるかわからないので一応3.5f

	m_fillFlag = FALSE;
}

Block::Block(ColliderInfo blockArgumentXY, BlockInfo blockArgument, int directionOfMovement)
	: BoxCollider({ blockArgumentXY })
{
	m_directionOfMove = directionOfMovement;

	blockInfo = blockArgument;

	m_downSpeed = 0.7; // どのくらいになるかわからないので一応0.7f
	m_lateralSpeed = 3.5; // どのくらいになるかわからないので一応3.5f

	m_fillFlag = FALSE;
}

//デストラクタ
Block::~Block()
{
	//未定
}

// ブロックの横移動
void Block::MoveBlockDown()
{
	collider.y1 += m_downSpeed;
	collider.y2 += m_downSpeed;
}

// ブロックの横移動
void LateralBlock::MoveBlockLateral()
{
	// コンストラクタに動く方向を持たせてそれを判定にしている
	collider.x1 += m_directionOfMove * m_lateralSpeed;
	collider.x2 += m_directionOfMove * m_lateralSpeed;
}

// 描画のみを扱う (引数に関しては "DrawBox"　の物を参照)
void Block::DrawBlock() const
{
	DrawBox((int)collider.x1, (int)collider.y1, (int)collider.x2, (int)collider.y2, blockInfo.color, blockInfo.fillFlag);
}

void Block::UpdateBlock()
{
	if (!m_onCollision)
	{
		MoveBlockLateral(); // 横移動
	}
	else
	{
		MoveBlockDown(); // 下移動
		SetFillBlock(); // ブロックの塗りつぶし
	}
}

// 画面外かの判定
bool Block::IsOffScreen() const
{
	// 上辺が画面下より下の場合　右辺が画面左ー５０座標より少ないとき　左辺が画面右＋２００座標より多いときに消える
	// 左右＋２００にしているのは生成してすぐ消えないようにするため（今後増やすかも）　
	return collider.y1 > WIN_SIZE_Y || collider.x2 < -200 || collider.x1 > WIN_SIZE_X + 200;
}

// ブロックの色埋め
void Block::SetFillBlock()
{
	blockInfo.fillFlag = TRUE;
}


void Block::CollisionEnter(BoxCollider* other)
{
	SetOnCollisionTrue();
}