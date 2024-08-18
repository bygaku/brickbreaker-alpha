////////////////�{�[��.cpp////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#include "ball.h"

//�ϐ�
float pvx, pvy;

int ballR = BALLR;

/////////////////////////////////////////////////////////////////////////////////////
// �񋓌^
/////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	BALL_ALIVE,     // �{�[���������Ă���
	BALL_RESET,		// �{�[�������Z�b�g
}BallStatusEnum;

//�񋓂��X�e�[�^�X�ɓ����
BallStatusEnum Status;

// �֐�
/////////////////////////////////////////////////////////////////////////////////////
// �{�[���̏�����
/////////////////////////////////////////////////////////////////////////////////////
void BallInit()
{
	//Status = BALL_RESET;

	//�o�[�̏�ɔz�u
	ballPx;
	ballPy - ballR;
	ballVx;
	ballVy;
}


/////////////////////////////////////////////////////////////////////////////////////
// �{�[���̍X�V
/////////////////////////////////////////////////////////////////////////////////////
void BallUpdate()
{

	if (spacePressedLastFrame % 2 == 1) 
	{
		//X���ւ̈ړ�
		ballPx += ballVx;
		if (ballPx < ballR && ballVx < 0)
		{
			ballVx = -ballVx;
		}

		if (ballPx > SCREEN_X - ballR && ballVx > 0) 
		{
			ballVx = -ballVx;
		}

		//Y���ւ̈ړ�
		ballPy += ballVy;
		if (ballPy < ballR && ballVy < 0) 
		{
			ballVy = -ballVy;
		}

		if (ballPy > SCREEN_Y - ballR && ballVy > 0) 
		{
			ballVy = -ballVy;

			//��ʉ��Ƀ{�[�����X�e�[�^�X��DEAD�ɂ���
			//gameOverFlag = SCREEN_YMaxHitCheck();
			gameOverFlag = TRUE;
		}
	}
	else
	{
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			ballPx -= 10;

			//���ɍs�����Ƃ�
			if (ballPx < 60) {
				ballPx = 60;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			ballPx += 10;

			//�E�ɍs�����Ƃ�
			if (ballPx > SCREEN_X - 60) {
				ballPx = SCREEN_X - 60;
			}
		}
	}


	/*
	switch (Status)
	{
	case BALL_RESET:		  // �{�[���̏����ʒu�A���X�^�[�g��
		//ballUpdateReset();
		break;
	case BALL_ALIVE:          // �{�[���������Ă���
		//ballUpdateAlive();

		//X���ւ̈ړ�
		ballPx += ballVx;
		if (ballPx < ballR && ballVx < 0) {
			ballVx = -ballVx;
		}

		if (ballPx > SCREEN_X - ballR && ballVx > 0) {
			ballVx = -ballVx;
		}

		//Y���ւ̈ړ�
		ballPy += ballVy;
		if (ballPy < ballR && ballVy < 0) {
			ballVy = -ballVy;
		}

		if (ballPy > SCREEN_Y - ballR && ballVy > 0) {
			ballVy = -ballVy;

		}

		//��ʉ��Ƀ{�[�����X�e�[�^�X��DEAD�ɂ���
		gameOverFlag = SCREEN_YMaxHitCheck();

		break;
	}
	*/

}

//////////////////////////////////////////////////////////
// �{�[���̕`��
//////////////////////////////////////////////////////////
void BallDraw()
{
	// �~��`��
	DrawCircle(ballPx, ballPy - ballR, ballR, GetColor(255, 255, 255));
}


//////////////////////////////////////////////////////////
// �{�[���̃��Z�b�g
//////////////////////////////////////////////////////////
void BallFinalize() 
{
	ballPx = SCREEN_X / 2;
	ballPy = SCREEN_Y - (SCREEN_Y / 5 - BALLR) - BALLR - ballR;
}

//////////////////////////////////////////////////////////
// �{�[���̓����蔻��
//////////////////////////////////////////////////////////
bool SCREEN_YMaxHitCheck()
{
	//�v���C���[���������������Ă��Ȃ��Ƃ��͏������Ȃ�
	if (Status != BALL_ALIVE)
		return FALSE;

	if (ballPy > SCREEN_Y - ballR && ballVy > 0) {

		return TRUE;
	}

	return FALSE;
}

void ballUpdateReset()
{
	//�o�[�̏�ɔz�u
	ballPx;
	ballPy - ballR;
	ballVx = 0; ballVy = 0;
}


/*
void ballUpdateAlive()
{
	//X���ւ̈ړ�
	ballPx += ballVx;
	if (ballPx < ballR && ballVx < 0) {
		ballVx = -ballVx;
	}

	if (ballPx > SCREEN_X - ballR && ballVx > 0) {
		ballVx = -ballVx;
	}

	//Y���ւ̈ړ�
	ballPy += ballVy;
	if (ballPy < ballR && ballVy < 0) {
		ballVy = -ballVy;
	}

	if (ballPy > SCREEN_Y - ballR && ballVy > 0) {
		ballVy = -ballVy;

		//��ʉ��Ƀ{�[�����X�e�[�^�X��DEAD�ɂ���
		gameEndFlag = SCREEN_YMaxHitCheck();
	}

	return;
}
*/

