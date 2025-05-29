#include "BoxCollider.h"

// コンストラクタ
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
{
	collider = colliderArgument;
	m_onCollisionEnter = false;
}

// デストラクタ
BoxCollider::~BoxCollider()
{

}

//当たり判定
bool BoxCollider::OnCollision()
{
	return 0; // (仮)
}

ColliderInfo BoxCollider::GetCclliderInfo()
{
	return collider;
}