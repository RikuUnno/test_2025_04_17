#pragma once

struct SpikInfo
{
	int x1, y1, x2, y2, x3, y3; // スパイクの位置情報
	unsigned int color; // スパイクの色
	int fillFlag; // 埋めるがどうか
	int sx; // スクリーンのサイズ
};

// 底辺のとげを作るクラス　
class UnderSpike
{
private:
	int m_offset; // とげの間隔
	int m_triangleX; // とげの長さ
	SpikInfo spikeinfo; // とげの位置等の情報

public:
	// 基本は三角形描画の関数の引数をもとにしている xy1は左辺　xy2は右辺　xy3は上辺の位置を入れるかつ基本は右に増やすので左端の座標とする
	// 最後の変数のみスクリーンのｘを入れる
	UnderSpike(unsigned int color, int fillFlag, int sx);

	void DrawSpike();

	int GetSpikeTopY() const { return spikeinfo.y3; } // とげの先端Y座標（上方向）
	};