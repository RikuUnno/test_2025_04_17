#include "BoxCollider.h"

// コンストラクタ
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
{
	collider = colliderArgument;
	m_onCollision = false;
}

// デストラクタ
BoxCollider::~BoxCollider()
{

}

// 当たり判定
void BoxCollider::SetOnCollisionTrue()
{
	m_onCollision = true;
}

// 当たり判定
void BoxCollider::SetOnCollisionFalse()
{
	m_onCollision = false;
}

// コライダーのゲッター
ColliderInfo BoxCollider::GetColliderInfo() const
{
	return collider;
}