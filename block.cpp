////////////////�u���b�N.cpp////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#include "block.h"

//�ϐ�
const int blockRow = 1;				//�u���b�N�̏c��
const int blockColumn = 4;			//�u���b�N�̉���
const int blockPattern = 4;			//�u���b�N�̎��
const int blockX = 5;               //�u���b�NX
const int blockY = 4;               //�u���b�NY

const int blockGreen = 0;           //�O���[��
const int blockRed = 1;             //���b�h
const int blockBlue = 2;            //�u���[
const int blockYellow = 3;          //�C�G���[

const int blockspaceX = 3;			//�u���b�N�̃X�y�[�X X����3��
const int blockspaceY = 3;			//�u���b�N�̃X�y�[�X Y����2��

float position_x, position_y;       //���W

int blockNowIndex;

int blockImg[blockRow * blockColumn];         //�摜�n���h��

int distant_x_l;		//left
int distant_x_r;		//right
int distant_y_u;		//up
int distant_y_d;		//down


bool BlockPos[blockY][blockX];


/////////////////////////////////////////////////////////////////////////////////////
// �񋓌^
/////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	BLOCK_ALIVE,     // �u���b�N�������Ă���
	BLOCK_DEAD,      // �u���b�N������
	BLOCK_RESET,	 // �u���b�N�����Z�b�g
}BlockStatusEnum;

//�񋓂��X�e�[�^�X�ɓ����
BlockStatusEnum Status;

// �֐�
/////////////////////////////////////////////////////////////////////////////////////
// �u���b�N�̏�����
/////////////////////////////////////////////////////////////////////////////////////
void BlockInit()
{
	int i, j;
	//�����ʒu
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	//�p�^�[��
	blockNowIndex = 0;

	//�p�^�[���������u���b�N��ǂݍ���
	for (i = 0; i < blockY; i++) {

		for (j = 0; j < blockX; j++) {
			//LoadDivGraph("image/BlockGame-0002.png", blockPattern, blockRow, blockColumn, BLOCK_SIZE_X, BLOCK_SIZE_Y, blockImg);

			//DrawBox(position_x, position_y, position_x + BLOCK_SIZE_X, position_y + BLOCK_SIZE_Y, GetColor(255, 255, 255), TRUE);
		}

	}

}


/////////////////////////////////////////////////////////////////////////////////////
// �u���b�N�̍X�V
/////////////////////////////////////////////////////////////////////////////////////
void BlockUpdate()
{
	
}

//////////////////////////////////////////////////////////
// �u���b�N�̕`��
//////////////////////////////////////////////////////////
void BlockDraw()
{
	int i, j;
	//������
	blockNowIndex = 0;
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	//�u���b�N�C���[�W��`��
	for (i = 0; i < blockY; i++) 
	{

		//�����ʒu�ɖ߂�
		position_x = SCREEN_X / blockX;

		for (j = 0; j < blockX; j++) 
		{
			BlockPos[i][j] = TRUE;

			if (BlockPos[i][j] = TRUE) {
				//DrawGraph(static_cast<int>(position_x), static_cast<int>(position_y), blockImg[blockNowIndex], TRUE);
				DrawBox(position_x, position_y, position_x + BLOCK_SIZE_X, position_y + BLOCK_SIZE_Y, GetColor(255, 255, 255), TRUE);
			}


			//X���W�ʒu�����炵�ĕ`��
			position_x += BLOCK_SIZE_X * blockspaceX;
		}
		//Y���W�ʒu�����炵�ĕ`��
		position_y += BLOCK_SIZE_Y * blockspaceY;

		//�F��ς��čĔz��
		blockNowIndex++;
	}
}


void blockHitCheck() 
{
	//�ϐ�
	int blockposX_l[blockY][blockX];
	int blockposX_r[blockY][blockX];
	int blockposY_u[blockY][blockX];
	int blockposY_d[blockY][blockX];
	int i, j;

	//������
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	for (i = 0; i < blockY; i++) 
	{

		//�����ʒu�ɖ߂�
		position_x = SCREEN_X / blockX;

		for (j = 0; j < blockX; j++) 
		{
			blockposX_l[i][j] = position_x;
			blockposY_u[i][j] = position_y;

			blockposX_r[i][j] = position_x + BLOCK_SIZE_X;
			blockposY_d[i][j] = position_y + BLOCK_SIZE_Y;

			position_x += BLOCK_SIZE_X * blockspaceX;
		}

		position_y += BLOCK_SIZE_Y * blockspaceY;

	}
	//�u���b�N�̕ϐ�������
	for (i = 0; i < blockY; i++) 
	{

		for (j = 0; j < blockX; j++) 
		{
			distant_x_l = ballPx - blockposX_l[i][j];
			distant_y_u = ballPy - blockposY_u[i][j];

			distant_x_r = ballPx - blockposX_r[i][j];
			distant_y_d = ballPy - blockposY_d[i][j];
		}

	}

	for (i = 0; i < blockY; i++) 
	{

		for (j = 0; j < blockX; j++) 
		{
			//�u���b�N�̏�ʂ̓����蔻��
			if ((blockposX_l[i][j] < ballPx) && (blockposX_r[i][j] > ballPx) && (0 < distant_y_u) && (distant_y_u < 20))
			{
				// �ڐG���Ă���
				ballVy = -5;
				BlockPos[i][j] = FALSE;


				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//�u���b�N�̉��ʂ̓����蔻��
			if ((blockposX_l[i][j] < ballPx) && (blockposX_r[i][j] > ballPx) && (-20 < distant_y_d) && (distant_y_d < 0))
			{
				// �ڐG���Ă���
				ballVy = +5;
				BlockPos[i][j] = FALSE;

				
				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//�u���b�N�̍��ʂ̓����蔻��
			if ((blockposY_u[i][j] < ballPy) && (blockposY_d[i][j] > ballPy) && (0 < distant_x_l) && (distant_x_l < 20))
			{
				// �ڐG���Ă���
				ballVx = -5;
				BlockPos[i][j] = FALSE;


				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//�u���b�N�̉E�ʂ̓����蔻��
			if ((blockposY_u[i][j] < ballPy) && (blockposY_d[i][j] > ballPy) && (-20 < distant_x_r) && (distant_x_r < 0))
			{
				// �ڐG���Ă���
				ballVx = +5;
				BlockPos[i][j] = FALSE;


				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			if (BlockPos[i][j] == FALSE) 
			{

			}
		}

	}


}