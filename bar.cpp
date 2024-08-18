////////////////バー.cpp////////////////

// ライブラリ＆ヘッダーファイル読み込み
#include "bar.h"

//変数
int barH = BAR_HEIGHT;
int barW = BAR_WIDTH;

int barX = SCREEN_X / 2;
int barY = SCREEN_Y - (SCREEN_Y / 5);

int dx;     //X軸方向の距離
int dy;     //Y軸方向の距離


//関数
/////////////////////////////////////////////////////////////////////////////////////
// バーの初期化
/////////////////////////////////////////////////////////////////////////////////////
void BarInit()
{
	//バーの上に配置
	barX;
	barY;
}


/////////////////////////////////////////////////////////////////////////////////////
// バーの更新
/////////////////////////////////////////////////////////////////////////////////////
void BarUpdate()
{
    /*
    if (spacePressedLastFrame == 1) 
    {
        if (CheckHitKey(KEY_INPUT_LEFT) == 1) 
        {
            barX -= 10;

            //左に行ったとき
            if (barX < barW / 2) 
            {
                barX = barW / 2;
            }
        }
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
        {
            barX += 10;

            //右に行ったとき
            if (barX > SCREEN_X - barW / 2) 
            {
                barX = SCREEN_X - barW / 2;
            }
        }

    }
    */

    if (CheckHitKey(KEY_INPUT_LEFT) == 1) 
    {
        barX -= 10;

        //左に行ったとき
        if (barX < barW / 2)
        {
            barX = barW / 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
    {
        barX += 10;

        //右に行ったとき
        if (barX > SCREEN_X - barW / 2) 
        {
            barX = SCREEN_X - barW / 2;
        }
    }
}

//////////////////////////////////////////////////////////
// バーの描画
//////////////////////////////////////////////////////////
void BarDraw()
{
	// バーを描画
    DrawBox(barX - (BAR_WIDTH / 2), barY, barX + (BAR_WIDTH / 2), barY + BAR_HEIGHT, GetColor(255, 255, 255), TRUE);
}

void BarFinalize()
{
    barX = SCREEN_X / 2;
    barY = SCREEN_Y - (SCREEN_Y / 5); 
}

//////////////////////////////////////////////////////////
// バーの当たり判定
//////////////////////////////////////////////////////////
void barHitCheck() 
{

    dx = ballPx - barX;     //X軸方向の距離
    dy = ballPy - barY;     //Y軸方向の距離

    if (-barW / 2 - BALLR < dx && dx < barW / 2 + BALLR && 0 < dy && dy < 20)
    {
        // 接触している
        ballVy = -5;


        //Barに触れたら鳴らす鳴らす
        PlaySoundMem(UISound_4, DX_PLAYTYPE_BACK);
        
    }
    
}