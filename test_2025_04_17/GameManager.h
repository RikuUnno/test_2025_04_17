#pragma once

class GameManager
{
private:
	int point = -1;

private:
	GameManager() {} // コンストラクタ

	GameManager(const GameManager&) = delete;				// コピコンの禁止
	GameManager& operator=(const GameManager&) = delete;	// 代入の禁止

public:
	static GameManager& GetInstance() {
		static GameManager instance;
		return instance;
	}

	int GetPoint() const { return point; }
	void SetPoint(int addPoint) { point += addPoint; }

};