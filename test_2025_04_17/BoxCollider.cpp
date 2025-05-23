#include "BoxCollider.h"

// コンストラクタ
BoxCollider::BoxCollider(ColliderInfo collider)
{
	m_onCollisionEnter = false;
}

// デストラクタ
BoxCollider::~BoxCollider()
{

}

//当たり判定
bool BoxCollider::OnCollision()
{
	
}