

//タイトル
void TITLE() {
    BlockInit();
    BallInit();
}

//プレイ中
void PLAY() {
    // 画面を初期化する
    ClearDrawScreen();

    BlockUpdate();
    BlockDraw();

    BallUpdate();
    BallDraw();


    // 裏画面の内容を表画面に反映させる
    ScreenFlip();
}

//リザルト画面
void OVER() {
    inputFinish();
}