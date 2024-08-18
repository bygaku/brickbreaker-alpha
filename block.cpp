////////////////ブロック.cpp////////////////

// ライブラリ＆ヘッダーファイル読み込み
#include "block.h"

//変数
const int blockRow = 1;				//ブロックの縦列
const int blockColumn = 4;			//ブロックの横列
const int blockPattern = 4;			//ブロックの種類
const int blockX = 5;               //ブロックX
const int blockY = 4;               //ブロックY

const int blockGreen = 0;           //グリーン
const int blockRed = 1;             //レッド
const int blockBlue = 2;            //ブルー
const int blockYellow = 3;          //イエロー

const int blockspaceX = 3;			//ブロックのスペース X軸に3つ分
const int blockspaceY = 3;			//ブロックのスペース Y軸に2つ分

float position_x, position_y;       //座標

int blockNowIndex;

int blockImg[blockRow * blockColumn];         //画像ハンドル

int distant_x_l;		//left
int distant_x_r;		//right
int distant_y_u;		//up
int distant_y_d;		//down


bool BlockPos[blockY][blockX];


/////////////////////////////////////////////////////////////////////////////////////
// 列挙型
/////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	BLOCK_ALIVE,     // ブロックが生きている
	BLOCK_DEAD,      // ブロックが死んだ
	BLOCK_RESET,	 // ブロックがリセット
}BlockStatusEnum;

//列挙をステータスに入れる
BlockStatusEnum Status;

// 関数
/////////////////////////////////////////////////////////////////////////////////////
// ブロックの初期化
/////////////////////////////////////////////////////////////////////////////////////
void BlockInit()
{
	int i, j;
	//初期位置
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	//パターン
	blockNowIndex = 0;

	//パターン数だけブロックを読み込む
	for (i = 0; i < blockY; i++) {

		for (j = 0; j < blockX; j++) {
			//LoadDivGraph("image/BlockGame-0002.png", blockPattern, blockRow, blockColumn, BLOCK_SIZE_X, BLOCK_SIZE_Y, blockImg);

			//DrawBox(position_x, position_y, position_x + BLOCK_SIZE_X, position_y + BLOCK_SIZE_Y, GetColor(255, 255, 255), TRUE);
		}

	}

}


/////////////////////////////////////////////////////////////////////////////////////
// ブロックの更新
/////////////////////////////////////////////////////////////////////////////////////
void BlockUpdate()
{
	
}

//////////////////////////////////////////////////////////
// ブロックの描画
//////////////////////////////////////////////////////////
void BlockDraw()
{
	int i, j;
	//初期化
	blockNowIndex = 0;
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	//ブロックイメージを描写
	for (i = 0; i < blockY; i++) 
	{

		//初期位置に戻す
		position_x = SCREEN_X / blockX;

		for (j = 0; j < blockX; j++) 
		{
			BlockPos[i][j] = TRUE;

			if (BlockPos[i][j] = TRUE) {
				//DrawGraph(static_cast<int>(position_x), static_cast<int>(position_y), blockImg[blockNowIndex], TRUE);
				DrawBox(position_x, position_y, position_x + BLOCK_SIZE_X, position_y + BLOCK_SIZE_Y, GetColor(255, 255, 255), TRUE);
			}


			//X座標位置をずらして描写
			position_x += BLOCK_SIZE_X * blockspaceX;
		}
		//Y座標位置をずらして描写
		position_y += BLOCK_SIZE_Y * blockspaceY;

		//色を変えて再配列
		blockNowIndex++;
	}
}


void blockHitCheck() 
{
	//変数
	int blockposX_l[blockY][blockX];
	int blockposX_r[blockY][blockX];
	int blockposY_u[blockY][blockX];
	int blockposY_d[blockY][blockX];
	int i, j;

	//初期化
	position_x = SCREEN_X / blockX;
	position_y = SCREEN_Y - (SCREEN_Y - 80);

	for (i = 0; i < blockY; i++) 
	{

		//初期位置に戻す
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
	//ブロックの変数を入れる
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
			//ブロックの上面の当たり判定
			if ((blockposX_l[i][j] < ballPx) && (blockposX_r[i][j] > ballPx) && (0 < distant_y_u) && (distant_y_u < 20))
			{
				// 接触している
				ballVy = -5;
				BlockPos[i][j] = FALSE;


				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//ブロックの下面の当たり判定
			if ((blockposX_l[i][j] < ballPx) && (blockposX_r[i][j] > ballPx) && (-20 < distant_y_d) && (distant_y_d < 0))
			{
				// 接触している
				ballVy = +5;
				BlockPos[i][j] = FALSE;

				
				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//ブロックの左面の当たり判定
			if ((blockposY_u[i][j] < ballPy) && (blockposY_d[i][j] > ballPy) && (0 < distant_x_l) && (distant_x_l < 20))
			{
				// 接触している
				ballVx = -5;
				BlockPos[i][j] = FALSE;


				PlaySoundMem(UISound_3, DX_PLAYTYPE_BACK);

			}

			//ブロックの右面の当たり判定
			if ((blockposY_u[i][j] < ballPy) && (blockposY_d[i][j] > ballPy) && (-20 < distant_x_r) && (distant_x_r < 0))
			{
				// 接触している
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