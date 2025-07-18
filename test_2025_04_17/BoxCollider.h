#pragma once
#include <vector>

class Block;

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollision; // 当たり判定

	std::vector<BoxCollider*> currentHitColliders; // 現在のフレームで当たったやつ
	std::vector<BoxCollider*> previousHitColliders; // 前フレームの当たったやつ

public:
	// コンストラクタ
	BoxCollider(ColliderInfo collider);

	// デストラクタ
	virtual ~BoxCollider();

	void SetOnCollisionTrue() { m_onCollision = true; } // m_onCollisionのセッター

	void SetOnCollisionFalse() { m_onCollision = false; } // m_onCollisionのセッター

	bool GetOnCollision() const { return m_onCollision; } // m_onCollisionのゲッター

	ColliderInfo GetColliderInfo() const; // コライダーのゲッター

	void CheckCollisionEvent(); // イベントチェック

	void AddCurrentHitCollider(BoxCollider* box); // currentHitCollidersに追加

public:
	virtual void CollisionEnter(BoxCollider* other) {} // 接触直後
	virtual void CollisionStay(BoxCollider* other) {} // 接触中
	virtual void CollisionExit(BoxCollider* other) {} // 接触後 
};