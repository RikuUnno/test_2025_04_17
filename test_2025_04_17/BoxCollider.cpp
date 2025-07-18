#include "BoxCollider.h"

// コンストラクタ
BoxCollider::BoxCollider(ColliderInfo colliderArgument)
	:collider(colliderArgument), m_onCollision(false)
{}

BoxCollider::~BoxCollider()
{}

// コライダーのゲッター
ColliderInfo BoxCollider::GetColliderInfo() const
{
	return collider;
}

void BoxCollider::AddCurrentHitCollider(BoxCollider* box)
{
    currentHitColliders.push_back(box);
}

void BoxCollider::CheckCollisionEvent()
{
    for (BoxCollider* other : currentHitColliders)
    {
        if (std::find(previousHitColliders.begin(), previousHitColliders.end(), other) == previousHitColliders.end())
        {
            CollisionEnter(other); // 初めて当たった
        }
        else
        {
            CollisionStay(other); // 前も今も当たってる
        }
    }

    for (BoxCollider* other : previousHitColliders)
    {
        if (std::find(currentHitColliders.begin(), currentHitColliders.end(), other) == currentHitColliders.end())
        {
            CollisionExit(other); // 今回は当たっていない
        }
    }

    previousHitColliders = currentHitColliders; // 前の状態を更新
    currentHitColliders.clear(); // 今の状態は初期化
}