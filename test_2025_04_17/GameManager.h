#pragma once

class GameManager
{
private:
	int point = -1;

private:
	GameManager() {} // �R���X�g���N�^

	GameManager(const GameManager&) = delete;				// �R�s�R���̋֎~
	GameManager& operator=(const GameManager&) = delete;	// ����̋֎~

public:
	static GameManager& GetInstance() {
		static GameManager instance;
		return instance;
	}

	int GetPoint() const { return point; }
	void SetPoint(int addPoint) { point += addPoint; }

};