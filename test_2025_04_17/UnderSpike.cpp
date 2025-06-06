#include "UnderSpike.h"
#include "GameInfo.h"
#include "DxLib.h"

// 基本は三角形描画の関数の引数をもとにしている xy1は左辺　xy2は右辺　xy3は上辺の位置を入れるかつ基本は右に増やすので左端の座標とする
// 最後の変数のみスクリーンのｘを入れる
UnderSpike::UnderSpike(unsigned int color, int fillFlag, int sx)
{ 
	spikeinfo = { 0, 
		WIN_SIZE_Y, 
		WIN_SIZE_X / 12, 
		WIN_SIZE_Y, 
		(WIN_SIZE_X / 12) / 2, 
		WIN_SIZE_Y / 15 * 14, 
		color, fillFlag, sx };

	m_offset = WIN_SIZE_X / 12;
	m_triangleX = 0;
}

void UnderSpike::DrawSpike()
{
	do
	{
		m_triangleX = spikeinfo.x2; // 長さの合計値の加算

		DrawTriangle(spikeinfo.x1, spikeinfo.y1, spikeinfo.x2, spikeinfo.y2, spikeinfo.x3, spikeinfo.y3, spikeinfo.color, spikeinfo.fillFlag); // 描画処理

		spikeinfo.x1 = spikeinfo.x2; // 次の左辺のｘの更新
		spikeinfo.x2 = spikeinfo.x2 + m_offset; // 次の右辺のｘの更新
		spikeinfo.x3 += m_offset; // 次の上辺のｘの更新
	} while (m_triangleX < spikeinfo.sx);
	spikeinfo.x1 -= m_triangleX; // 最初の値に戻す
	spikeinfo.x2 -= m_triangleX; // 最初の値に戻す
	spikeinfo.x3 -= m_triangleX; // 最初の値に戻す
}
