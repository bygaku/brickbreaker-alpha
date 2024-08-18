////////////////ゲームデータ.h////////////////

// ライブラリ＆ヘッダーファイル読み込み
#pragma once
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////
// 定数 (このslnファイルにおいて変わることがないもの)
/////////////////////////////////////////////////////////////////////////////////////

#define SCREEN_X		920			// スクリーンの横比率の大きさ
#define SCREEN_Y		680			// スクリーンの縦比率の大きさ
#define START_STRING_X	230			// スタート画面の文字　X座標
#define START_STRING_Y	520			// スタート画面の文字　Y座標
#define RESULT_STRINGS_X 15			// リザルト画面の文字　X座標
#define RESULT_STRINGS_Y 15			// リザルト画面の文字　Y座標
								   
#define BLOCK_SIZE_X	 42			// ブロックサイズ横比率の大きさ
#define BLOCK_SIZE_Y	 10			// ブロックサイズ縦比率の大きさ

//#define BLOCK_SIZE_X	 84			// ブロックサイズ横比率の大きさ
//#define BLOCK_SIZE_Y	 30			// ブロックサイズ縦比率の大きさ

#define BAR_X SCREEN_X  / 2			// バー初期座標　X
#define BAR_Y SCREEN_Y  / 5			// バー初期座標　Y
#define BAR_WIDTH	    120			// バーサイズ横の大きさ
#define BAR_HEIGHT		 10			// バーサイズ縦の大きさ
#define BALLR			 10			// ボールの半径

/////////////////////////////////////////////////////////////////////////////////////
// ゲームフラグ
/////////////////////////////////////////////////////////////////////////////////////

extern bool gameStartFlag ;			// ゲーム開始フラグ
extern bool gameEndFlag   ;			// ゲーム終了フラグ
extern bool gameOverFlag  ;			// ゲームオーバーフラグ
extern bool gameClearFlag ;			// ゲームクリアフラグ

extern bool spacePressFlag;			// Spaceが押されたかどうか
extern bool spacePressedLastFrame;			// Spaceが押されたかどうか
extern bool spacePressAllowed    ;			// Spaceを押されているかどうか

/////////////////////////////////////////////////////////////////////////////////////
// 列挙型
/////////////////////////////////////////////////////////////////////////////////////
enum SCENE {
    TITLE,
    PLAY,
    OVER,
    CLEAR,
};

extern enum SCENE NowGameScene;
/////////////////////////////////////////////////////////////////////////////////////
// 円、バー初期設定関連
/////////////////////////////////////////////////////////////////////////////////////
extern float vx;		
extern float vy;		//速度

extern float ballVx;	
extern float ballVy;	//ボールの速度
extern float ballPx;
extern float ballPy;	//ボールposition

extern int UISound_1;
extern int UISound_2;
extern int UISound_3;
extern int UISound_4;

extern int startScreenImage;
extern int pressStartImage ;
extern int gameEndImage    ;
extern int gameClearImage  ;

extern int spacePressCount ;          //スペースキーカウント
/////////////////////////////////////////////////////////////////////////////////////
// 関数プロトタイプ宣言
/////////////////////////////////////////////////////////////////////////////////////
void inputFinish();