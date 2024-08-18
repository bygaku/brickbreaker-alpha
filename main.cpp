////////////////�Q�[�����C��.cpp////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#include "DxLib.h"
#include <stdio.h>
#include "gamedata.h"
#include "ball.h"
#include "block.h"
#include "bar.h"
#include "loadScene.h"


// ���C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /////////////////////////////////////////////////////////////////////////////////////
    //�@��ʏ����ݒ�
    /////////////////////////////////////////////////////////////////////////////////////
    DxLib_Init();
    ChangeWindowMode(TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(SCREEN_X, SCREEN_Y, 16);           // 60���t���b�V�����[�g�A16�J���[�r�b�g�f�v�X�A��ʃT�C�Y�igamedata.h�̒萔�Q�Ɓj
    SetMainWindowText("BRICK BREAKER");             // �e�L�X�g��\��������


    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;             // �G���[���N�����璼���ɏI��
    }

    ///////////////////////////////////////////////////////////////////////////////���\�[�X����������
    NowGameScene = TITLE;

    //�ϐ�
    //�Q�[���t���[���J�E���g
    double frameCount = 0;
    int currentTime;
    int lastTime = 0;

    currentTime = lastTime - GetNowCount();

    //�^�C�}�[
    int timer = 0;

    /////////////////////////////////////////////////////////////////////////////////////
    //�Q�[���f�U�C�������ݒ�֘A
    /////////////////////////////////////////////////////////////////////////////////////

    //�T�E���h���������ɒǉ�
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

        //�Q�[���t���[���J�E���g
        double deltaTime = (currentTime - lastTime) / 1000.0;
        frameCount += deltaTime * 1000.0;
        ClearDrawScreen();
        timer++;

        // ��ʂ�����������
        ClearDrawScreen();

        /*
        if (spacePressAllowed && CheckHitKey(KEY_INPUT_SPACE) == TRUE && spacePressedLastFrame) 
        {
            spacePressCount++;

            if (spacePressCount % 2 == 1) 
            {
                //�Q�[���̊J�n
                gameStartFlag = TRUE;
                gameEndFlag = FALSE;
            }
            else 
            {
                //�Q�[���̏I���t���O
                gameStartFlag = FALSE;
                gameEndFlag = TRUE;
                spacePressFlag = FALSE;
            }
        }

        //�G���^�[�L�[�������ꂽ�����L������
        spacePressedLastFrame = CheckHitKey(KEY_INPUT_SPACE);

        if (spacePressCount == 0) {
            TITLE();
            // ����ʂ̓��e��\��ʂɔ��f������
            ScreenFlip();
        }

        if (gameStartFlag == TRUE) {
            PLAY();
            // ����ʂ̓��e��\��ʂɔ��f������
            ScreenFlip();
        }

        if (gameEndFlag == TRUE) {
            OVER();
            // ����ʂ̓��e��\��ʂɔ��f������
            ScreenFlip();
        }
        */

        //�V�[���؂�ւ�
        switch (NowGameScene)
        {
        case TITLE:

            //�X�^�[�g��ʂ̉摜���������ɒǉ�
            startScreenImage = LoadGraph("image/BRICKBREAKER_START.png");
            pressStartImage = LoadGraph("image/PRESS_START.png");


            //�摜�̕`��
            DrawGraph(0, 0, startScreenImage, TRUE);
            if (timer % 60 < 30) {
                DrawGraph(SCREEN_X / 2 - 115, SCREEN_Y - (SCREEN_Y / 4), pressStartImage, TRUE);
            }

            //�X�y�[�X�L�[���͂��L�^
            spacePressCount += CheckHitKey(KEY_INPUT_SPACE) == TRUE;

            if (spacePressCount == 1) {
                DeleteGraph(startScreenImage);
                DeleteGraph(pressStartImage);
                PlaySoundMem(UISound_1, DX_PLAYTYPE_NORMAL);
                NowGameScene = PLAY;

                //�L�^�����Z�b�g
                spacePressCount = 0;
            }

            break;
        case PLAY:
            //�G���^�[�L�[�������ꂽ�����L������
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
            //���Z�b�g
            gameEndFlag = false;
            gameOverFlag = false;

            BarFinalize();
            BallFinalize();

            //�L�^�����Z�b�g
            spacePressCount = 0;
            //spacePressedLastFrame = 0;


            //�Q�[���I�[�o�[��ʂ̉摜���������ɒǉ�
            gameEndImage = LoadGraph("image/BRICKBREAKER_BREAK.png");


            //�摜�̕`��
            DrawGraph(0, 0, gameEndImage, TRUE);
            if (CheckHitKey(KEY_INPUT_R) == TRUE) {
                DeleteGraph(gameEndImage);
            }

            //R���������ƃ��X�^�[�g�AEsc���������ƃ\�t�g�I��
            inputFinish();

            break;

        case CLEAR:
            //�Q�[���I�[�o�[��ʂ̉摜���������ɒǉ�
            gameClearImage = LoadGraph("image/BRICKBREAKER_CLEAR.png");


            //�摜�̕`��
            DrawGraph(0, 0, gameClearImage, TRUE);
            if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE) {
                DeleteGraph(gameClearImage);
            }

            break;
        }
        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();
    }


    //�I���錾
    DxLib_End();        // �c�w���C�u�����g�p�̏I������
    return 0;           // �\�t�g�̏I��

}
