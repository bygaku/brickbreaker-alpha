////////////////ブロック.h////////////////

// ライブラリ＆ヘッダーファイル読み込み
#pragma once
#include "gamedata.h"

/////////////////////////////////////////////////////////////////////////////////////
// 関数プロトタイプ宣言
/////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// ブロックの初期化
/// </summary>
void BlockInit();

/// <summary>
/// ブロック更新　１フレームごとの更新
/// </summary>
/// <param name="deltaTime">1フレーム分の処理時間</param>
void BlockUpdate();

/// <summary>
/// ブロック出現
/// </summary>
void BlockDraw();

/// <summary>
/// ブロック当たり判定
/// </summary>
void blockHitCheck();

