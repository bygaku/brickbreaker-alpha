////////////////ゲームデータ.cpp////////////////

// ライブラリ＆ヘッダーファイル読み込み
#include "gamedata.h"


/////////////////////////////////////////////////////////////////////////////////////
// ゲームフラグ
/////////////////////////////////////////////////////////////////////////////////////

bool gameStartFlag = false;				// ゲーム開始フラグ
bool gameEndFlag = false;				// ゲーム終了フラグ
bool gameOverFlag = false;				// ゲームオーバーフラグ
bool gameClearFlag = false;				// ゲームクリアフラグ
bool spacePressFlag = false;			// Spaceが押されたかどうか
bool spacePressedLastFrame = false;		// Spaceが押されたかどうか
bool spacePressAllowed = true;			// Spaceを押されているかどうか

/////////////////////////////////////////////////////////////////////////////////////
// 列挙型
/////////////////////////////////////////////////////////////////////////////////////
//ゲームシーン
enum SCENE NowGameScene;        //現在のゲームシーン

/////////////////////////////////////////////////////////////////////////////////////
// 円、バー初期設定関連
/////////////////////////////////////////////////////////////////////////////////////

float vx = 5.0f;
float vy = 5.0f;

float ballVx = vx;
float ballVy = vy;
float ballPx = SCREEN_X / 2;
float ballPy = SCREEN_Y - (SCREEN_Y / 5 - BALLR) - BALLR;

int UISound_1;
int UISound_2;
int UISound_3;
int UISound_4;

int startScreenImage;
int pressStartImage ;
int gameEndImage    ;
int gameClearImage  ;

int spacePressCount ;
/////////////////////////////////////////////////////////////////////////////////////
// 関数プロトタイプ宣言
/////////////////////////////////////////////////////////////////////////////////////
void inputFinish() {
	if (CheckHitKey(KEY_INPUT_R) == TRUE) {
		NowGameScene = TITLE;
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE) {

		//終了宣言
		DxLib_End();        // ＤＸライブラリ使用の終了処理
		return;				// ソフトの終了

	}
}