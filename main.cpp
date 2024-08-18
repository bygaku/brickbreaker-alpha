////////////////ゲームメイン.cpp////////////////

// ライブラリ＆ヘッダーファイル読み込み
#include "DxLib.h"
#include <stdio.h>
#include "gamedata.h"
#include "ball.h"
#include "block.h"
#include "bar.h"
#include "loadScene.h"


// メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /////////////////////////////////////////////////////////////////////////////////////
    //　画面初期設定
    /////////////////////////////////////////////////////////////////////////////////////
    DxLib_Init();
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(SCREEN_X, SCREEN_Y, 16);           // 60リフレッシュレート、16カラービットデプス、画面サイズ（gamedata.hの定数参照）
    SetMainWindowText("BRICK BREAKER");             // テキストを表示させる


    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;             // エラーが起きたら直ちに終了
    }

    ///////////////////////////////////////////////////////////////////////////////リソース初期化処理
    NowGameScene = TITLE;

    //変数
    //ゲームフレームカウント
    double frameCount = 0;
    int currentTime;
    int lastTime = 0;

    currentTime = lastTime - GetNowCount();

    //タイマー
    int timer = 0;

    /////////////////////////////////////////////////////////////////////////////////////
    //ゲームデザイン初期設定関連
    /////////////////////////////////////////////////////////////////////////////////////

    //サウンドをメモリに追加
    UISound_1 = LoadSoundMem("sound/UIsound_1.wav");
    UISound_2 = LoadSoundMem("sound/UIsound_2.wav");
    UISound_3 = LoadSoundMem("sound/UIsound_3.wav");
    UISound_4 = LoadSoundMem("sound/UIsound_4.wav");

    BallInit();
    BarInit();
    BlockInit();


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        currentTime = GetNowCount();

        //ゲームフレームカウント
        double deltaTime = (currentTime - lastTime) / 1000.0;
        frameCount += deltaTime * 1000.0;
        ClearDrawScreen();
        timer++;

        // 画面を初期化する
        ClearDrawScreen();

        /*
        if (spacePressAllowed && CheckHitKey(KEY_INPUT_SPACE) == TRUE && spacePressedLastFrame) 
        {
            spacePressCount++;

            if (spacePressCount % 2 == 1) 
            {
                //ゲームの開始
                gameStartFlag = TRUE;
                gameEndFlag = FALSE;
            }
            else 
            {
                //ゲームの終了フラグ
                gameStartFlag = FALSE;
                gameEndFlag = TRUE;
                spacePressFlag = FALSE;
            }
        }

        //エンターキーが押されたかを記憶する
        spacePressedLastFrame = CheckHitKey(KEY_INPUT_SPACE);

        if (spacePressCount == 0) {
            TITLE();
            // 裏画面の内容を表画面に反映させる
            ScreenFlip();
        }

        if (gameStartFlag == TRUE) {
            PLAY();
            // 裏画面の内容を表画面に反映させる
            ScreenFlip();
        }

        if (gameEndFlag == TRUE) {
            OVER();
            // 裏画面の内容を表画面に反映させる
            ScreenFlip();
        }
        */

        //シーン切り替え
        switch (NowGameScene)
        {
        case TITLE:

            //スタート画面の画像をメモリに追加
            startScreenImage = LoadGraph("image/BRICKBREAKER_START.png");
            pressStartImage = LoadGraph("image/PRESS_START.png");


            //画像の描画
            DrawGraph(0, 0, startScreenImage, TRUE);
            if (timer % 60 < 30) {
                DrawGraph(SCREEN_X / 2 - 115, SCREEN_Y - (SCREEN_Y / 4), pressStartImage, TRUE);
            }

            //スペースキー入力を記録
            spacePressCount += CheckHitKey(KEY_INPUT_SPACE) == TRUE;

            if (spacePressCount == 1) {
                DeleteGraph(startScreenImage);
                DeleteGraph(pressStartImage);
                PlaySoundMem(UISound_1, DX_PLAYTYPE_NORMAL);
                NowGameScene = PLAY;

                //記録をリセット
                spacePressCount = 0;
            }

            break;
        case PLAY:
            //エンターキーが押されたかを記憶する
            spacePressedLastFrame += CheckHitKey(KEY_INPUT_SPACE);

            BallUpdate();
            BlockUpdate();
            BarUpdate();

            
            BlockDraw();
            BallDraw();
            BarDraw();

            barHitCheck();
            blockHitCheck();

            if (gameOverFlag == TRUE) {
                NowGameScene = OVER;
            }

            if (gameClearFlag == TRUE) {
                NowGameScene = CLEAR;
            }

            break;
        case OVER:
            //リセット
            gameEndFlag = false;
            gameOverFlag = false;

            BarFinalize();
            BallFinalize();

            //記録をリセット
            spacePressCount = 0;
            //spacePressedLastFrame = 0;


            //ゲームオーバー画面の画像をメモリに追加
            gameEndImage = LoadGraph("image/BRICKBREAKER_BREAK.png");


            //画像の描画
            DrawGraph(0, 0, gameEndImage, TRUE);
            if (CheckHitKey(KEY_INPUT_R) == TRUE) {
                DeleteGraph(gameEndImage);
            }

            //Rが押されるとリスタート、Escが押されるとソフト終了
            inputFinish();

            break;

        case CLEAR:
            //ゲームオーバー画面の画像をメモリに追加
            gameClearImage = LoadGraph("image/BRICKBREAKER_CLEAR.png");


            //画像の描画
            DrawGraph(0, 0, gameClearImage, TRUE);
            if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE) {
                DeleteGraph(gameClearImage);
            }

            break;
        }
        // 裏画面の内容を表画面に反映させる
        ScreenFlip();
    }


    //終了宣言
    DxLib_End();        // ＤＸライブラリ使用の終了処理
    return 0;           // ソフトの終了

}
