////////////////�o�[.cpp////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#include "bar.h"

//�ϐ�
int barH = BAR_HEIGHT;
int barW = BAR_WIDTH;

int barX = SCREEN_X / 2;
int barY = SCREEN_Y - (SCREEN_Y / 5);

int dx;     //X�������̋���
int dy;     //Y�������̋���


//�֐�
/////////////////////////////////////////////////////////////////////////////////////
// �o�[�̏�����
/////////////////////////////////////////////////////////////////////////////////////
void BarInit()
{
	//�o�[�̏�ɔz�u
	barX;
	barY;
}


/////////////////////////////////////////////////////////////////////////////////////
// �o�[�̍X�V
/////////////////////////////////////////////////////////////////////////////////////
void BarUpdate()
{
    /*
    if (spacePressedLastFrame == 1) 
    {
        if (CheckHitKey(KEY_INPUT_LEFT) == 1) 
        {
            barX -= 10;

            //���ɍs�����Ƃ�
            if (barX < barW / 2) 
            {
                barX = barW / 2;
            }
        }
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
        {
            barX += 10;

            //�E�ɍs�����Ƃ�
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

        //���ɍs�����Ƃ�
        if (barX < barW / 2)
        {
            barX = barW / 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
    {
        barX += 10;

        //�E�ɍs�����Ƃ�
        if (barX > SCREEN_X - barW / 2) 
        {
            barX = SCREEN_X - barW / 2;
        }
    }
}

//////////////////////////////////////////////////////////
// �o�[�̕`��
//////////////////////////////////////////////////////////
void BarDraw()
{
	// �o�[��`��
    DrawBox(barX - (BAR_WIDTH / 2), barY, barX + (BAR_WIDTH / 2), barY + BAR_HEIGHT, GetColor(255, 255, 255), TRUE);
}

void BarFinalize()
{
    barX = SCREEN_X / 2;
    barY = SCREEN_Y - (SCREEN_Y / 5); 
}

//////////////////////////////////////////////////////////
// �o�[�̓����蔻��
//////////////////////////////////////////////////////////
void barHitCheck() 
{

    dx = ballPx - barX;     //X�������̋���
    dy = ballPy - barY;     //Y�������̋���

    if (-barW / 2 - BALLR < dx && dx < barW / 2 + BALLR && 0 < dy && dy < 20)
    {
        // �ڐG���Ă���
        ballVy = -5;


        //Bar�ɐG�ꂽ��炷�炷
        PlaySoundMem(UISound_4, DX_PLAYTYPE_BACK);
        
    }
    
}