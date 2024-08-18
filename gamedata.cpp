////////////////�Q�[���f�[�^.cpp////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#include "gamedata.h"


/////////////////////////////////////////////////////////////////////////////////////
// �Q�[���t���O
/////////////////////////////////////////////////////////////////////////////////////

bool gameStartFlag = false;				// �Q�[���J�n�t���O
bool gameEndFlag = false;				// �Q�[���I���t���O
bool gameOverFlag = false;				// �Q�[���I�[�o�[�t���O
bool gameClearFlag = false;				// �Q�[���N���A�t���O
bool spacePressFlag = false;			// Space�������ꂽ���ǂ���
bool spacePressedLastFrame = false;		// Space�������ꂽ���ǂ���
bool spacePressAllowed = true;			// Space��������Ă��邩�ǂ���

/////////////////////////////////////////////////////////////////////////////////////
// �񋓌^
/////////////////////////////////////////////////////////////////////////////////////
//�Q�[���V�[��
enum SCENE NowGameScene;        //���݂̃Q�[���V�[��

/////////////////////////////////////////////////////////////////////////////////////
// �~�A�o�[�����ݒ�֘A
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
// �֐��v���g�^�C�v�錾
/////////////////////////////////////////////////////////////////////////////////////
void inputFinish() {
	if (CheckHitKey(KEY_INPUT_R) == TRUE) {
		NowGameScene = TITLE;
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE) {

		//�I���錾
		DxLib_End();        // �c�w���C�u�����g�p�̏I������
		return;				// �\�t�g�̏I��

	}
}