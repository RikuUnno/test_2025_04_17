#pragma once

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollision; // 当たり判定

public:
	// コンストラクタ
	BoxCollider(ColliderInfo collider);

	// デストラクタ
	virtual ~BoxCollider();

	void SetOnCollisionTrue(); // m_onCollisionのセッター

	void SetOnCollisionFalse(); // m_onCollisionのセッター

	ColliderInfo GetColliderInfo() const; // コライダーのゲッター
};