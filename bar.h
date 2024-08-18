////////////////バー.h////////////////

// ライブラリ＆ヘッダーファイル読み込み
#pragma once
#include "gamedata.h"

/////////////////////////////////////////////////////////////////////////////////////
// 関数プロトタイプ宣言
/////////////////////////////////////////////////////////////////////////////////////
void barHitCheck();

/// <summary>
/// バー初期化
/// </summary>
void BarInit();

/// <summary>
/// バー更新　１フレームごとの更新
/// </summary>
/// <param name="deltaTime">1フレーム分の処理時間</param>
void BarUpdate();

/// <summary>
/// バー出現
/// </summary>
void BarDraw();

/// <summary>
/// バー削除
/// </summary>
void BarFinalize();