#pragma once

#include "GameInfo.h"

class BoxCollider
{
protected:

public:
	// コンストラクタ
	BoxCollider(ColliderInfo);

	// デストラクタ
	virtual ~BoxCollider();

	//当たり判定
	void OnCollision();
};