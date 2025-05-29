#pragma once

#include "GameInfo.h"

struct ColliderInfo
{
	double x1, y1, x2, y2;
};

class BoxCollider
{
protected:
	ColliderInfo collider;
	bool m_onCollisionEnter; // 当たり判定

public:
	// コンストラクタ
	BoxCollider(ColliderInfo collider);

	// デストラクタ
	virtual ~BoxCollider();

	//当たり判定
	bool OnCollision();

	ColliderInfo GetCclliderInfo();
};