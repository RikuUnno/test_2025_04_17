#pragma once

#include "GameInfo.h"

class BoxCollider
{
protected:
	bool m_onCollisionEnter; // 当たり判定

public:
	// コンストラクタ
	BoxCollider(ColliderInfo collider);

	// デストラクタ
	virtual ~BoxCollider();

	//当たり判定
	bool OnCollision();
};