////////////////�Q�[���f�[�^.h////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#pragma once
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////
// �萔 (����sln�t�@�C���ɂ����ĕς�邱�Ƃ��Ȃ�����)
/////////////////////////////////////////////////////////////////////////////////////

#define SCREEN_X		920			// �X�N���[���̉��䗦�̑傫��
#define SCREEN_Y		680			// �X�N���[���̏c�䗦�̑傫��
#define START_STRING_X	230			// �X�^�[�g��ʂ̕����@X���W
#define START_STRING_Y	520			// �X�^�[�g��ʂ̕����@Y���W
#define RESULT_STRINGS_X 15			// ���U���g��ʂ̕����@X���W
#define RESULT_STRINGS_Y 15			// ���U���g��ʂ̕����@Y���W
								   
#define BLOCK_SIZE_X	 42			// �u���b�N�T�C�Y���䗦�̑傫��
#define BLOCK_SIZE_Y	 10			// �u���b�N�T�C�Y�c�䗦�̑傫��

//#define BLOCK_SIZE_X	 84			// �u���b�N�T�C�Y���䗦�̑傫��
//#define BLOCK_SIZE_Y	 30			// �u���b�N�T�C�Y�c�䗦�̑傫��

#define BAR_X SCREEN_X  / 2			// �o�[�������W�@X
#define BAR_Y SCREEN_Y  / 5			// �o�[�������W�@Y
#define BAR_WIDTH	    120			// �o�[�T�C�Y���̑傫��
#define BAR_HEIGHT		 10			// �o�[�T�C�Y�c�̑傫��
#define BALLR			 10			// �{�[���̔��a

/////////////////////////////////////////////////////////////////////////////////////
// �Q�[���t���O
/////////////////////////////////////////////////////////////////////////////////////

extern bool gameStartFlag ;			// �Q�[���J�n�t���O
extern bool gameEndFlag   ;			// �Q�[���I���t���O
extern bool gameOverFlag  ;			// �Q�[���I�[�o�[�t���O
extern bool gameClearFlag ;			// �Q�[���N���A�t���O

extern bool spacePressFlag;			// Space�������ꂽ���ǂ���
extern bool spacePressedLastFrame;			// Space�������ꂽ���ǂ���
extern bool spacePressAllowed    ;			// Space��������Ă��邩�ǂ���

/////////////////////////////////////////////////////////////////////////////////////
// �񋓌^
/////////////////////////////////////////////////////////////////////////////////////
enum SCENE {
    TITLE,
    PLAY,
    OVER,
    CLEAR,
};

extern enum SCENE NowGameScene;
/////////////////////////////////////////////////////////////////////////////////////
// �~�A�o�[�����ݒ�֘A
/////////////////////////////////////////////////////////////////////////////////////
extern float vx;		
extern float vy;		//���x

extern float ballVx;	
extern float ballVy;	//�{�[���̑��x
extern float ballPx;
extern float ballPy;	//�{�[��position

extern int UISound_1;
extern int UISound_2;
extern int UISound_3;
extern int UISound_4;

extern int startScreenImage;
extern int pressStartImage ;
extern int gameEndImage    ;
extern int gameClearImage  ;

extern int spacePressCount ;          //�X�y�[�X�L�[�J�E���g
/////////////////////////////////////////////////////////////////////////////////////
// �֐��v���g�^�C�v�錾
/////////////////////////////////////////////////////////////////////////////////////
void inputFinish();