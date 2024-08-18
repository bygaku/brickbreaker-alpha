////////////////ボール.h////////////////

// ライブラリ＆ヘッダーファイル読み込み
#pragma once
#include "gamedata.h"

/////////////////////////////////////////////////////////////////////////////////////
// 関数プロトタイプ宣言
/////////////////////////////////////////////////////////////////////////////////////
void ballUpdateReset();
void ballUpdateAlive();

/// <summary>
/// ボール初期化
/// </summary>
void BallInit();

/// <summary>
/// ボール更新　１フレームごとの更新
/// </summary>
/// <param name="deltaTime">1フレーム分の処理時間</param>
void BallUpdate();

/// <summary>
/// ボール出現
/// </summary>
void BallDraw();

/// <summary>
/// ボール削除
/// </summary>
void BallFinalize();

/// <summary>
/// ボールがY = MAXの位置かどうか
/// </summary>
bool SCREEN_YMaxHitCheck();
