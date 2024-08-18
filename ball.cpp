////////////////ボール.cpp////////////////

// ライブラリ＆ヘッダーファイル読み込み
#include "ball.h"

//変数
float pvx, pvy;

int ballR = BALLR;

/////////////////////////////////////////////////////////////////////////////////////
// 列挙型
/////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	BALL_ALIVE,     // ボールが生きている
	BALL_RESET,		// ボールがリセット
}BallStatusEnum;

//列挙をステータスに入れる
BallStatusEnum Status;

// 関数
/////////////////////////////////////////////////////////////////////////////////////
// ボールの初期化
/////////////////////////////////////////////////////////////////////////////////////
void BallInit()
{
	//Status = BALL_RESET;

	//バーの上に配置
	ballPx;
	ballPy - ballR;
	ballVx;
	ballVy;
}


/////////////////////////////////////////////////////////////////////////////////////
// ボールの更新
/////////////////////////////////////////////////////////////////////////////////////
void BallUpdate()
{

	if (spacePressedLastFrame % 2 == 1) 
	{
		//X軸への移動
		ballPx += ballVx;
		if (ballPx < ballR && ballVx < 0)
		{
			ballVx = -ballVx;
		}

		if (ballPx > SCREEN_X - ballR && ballVx > 0) 
		{
			ballVx = -ballVx;
		}

		//Y軸への移動
		ballPy += ballVy;
		if (ballPy < ballR && ballVy < 0) 
		{
			ballVy = -ballVy;
		}

		if (ballPy > SCREEN_Y - ballR && ballVy > 0) 
		{
			ballVy = -ballVy;

			//画面下にボールがステータスをDEADにする
			//gameOverFlag = SCREEN_YMaxHitCheck();
			gameOverFlag = TRUE;
		}
	}
	else
	{
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			ballPx -= 10;

			//左に行ったとき
			if (ballPx < 60) {
				ballPx = 60;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			ballPx += 10;

			//右に行ったとき
			if (ballPx > SCREEN_X - 60) {
				ballPx = SCREEN_X - 60;
			}
		}
	}


	/*
	switch (Status)
	{
	case BALL_RESET:		  // ボールの初期位置、リスタート時
		//ballUpdateReset();
		break;
	case BALL_ALIVE:          // ボールが生きている
		//ballUpdateAlive();

		//X軸への移動
		ballPx += ballVx;
		if (ballPx < ballR && ballVx < 0) {
			ballVx = -ballVx;
		}

		if (ballPx > SCREEN_X - ballR && ballVx > 0) {
			ballVx = -ballVx;
		}

		//Y軸への移動
		ballPy += ballVy;
		if (ballPy < ballR && ballVy < 0) {
			ballVy = -ballVy;
		}

		if (ballPy > SCREEN_Y - ballR && ballVy > 0) {
			ballVy = -ballVy;

		}

		//画面下にボールがステータスをDEADにする
		gameOverFlag = SCREEN_YMaxHitCheck();

		break;
	}
	*/

}

//////////////////////////////////////////////////////////
// ボールの描画
//////////////////////////////////////////////////////////
void BallDraw()
{
	// 円を描画
	DrawCircle(ballPx, ballPy - ballR, ballR, GetColor(255, 255, 255));
}


//////////////////////////////////////////////////////////
// ボールのリセット
//////////////////////////////////////////////////////////
void BallFinalize() 
{
	ballPx = SCREEN_X / 2;
	ballPy = SCREEN_Y - (SCREEN_Y / 5 - BALLR) - BALLR - ballR;
}

//////////////////////////////////////////////////////////
// ボールの当たり判定
//////////////////////////////////////////////////////////
bool SCREEN_YMaxHitCheck()
{
	//プレイヤーがそもそも生きていないときは処理しない
	if (Status != BALL_ALIVE)
		return FALSE;

	if (ballPy > SCREEN_Y - ballR && ballVy > 0) {

		return TRUE;
	}

	return FALSE;
}

void ballUpdateReset()
{
	//バーの上に配置
	ballPx;
	ballPy - ballR;
	ballVx = 0; ballVy = 0;
}


/*
void ballUpdateAlive()
{
	//X軸への移動
	ballPx += ballVx;
	if (ballPx < ballR && ballVx < 0) {
		ballVx = -ballVx;
	}

	if (ballPx > SCREEN_X - ballR && ballVx > 0) {
		ballVx = -ballVx;
	}

	//Y軸への移動
	ballPy += ballVy;
	if (ballPy < ballR && ballVy < 0) {
		ballVy = -ballVy;
	}

	if (ballPy > SCREEN_Y - ballR && ballVy > 0) {
		ballVy = -ballVy;

		//画面下にボールがステータスをDEADにする
		gameEndFlag = SCREEN_YMaxHitCheck();
	}

	return;
}
*/

