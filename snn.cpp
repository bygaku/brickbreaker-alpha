

//�^�C�g��
void TITLE() {
    BlockInit();
    BallInit();
}

//�v���C��
void PLAY() {
    // ��ʂ�����������
    ClearDrawScreen();

    BlockUpdate();
    BlockDraw();

    BallUpdate();
    BallDraw();


    // ����ʂ̓��e��\��ʂɔ��f������
    ScreenFlip();
}

//���U���g���
void OVER() {
    inputFinish();
}