////////////////�{�[��.h////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#pragma once
#include "gamedata.h"

/////////////////////////////////////////////////////////////////////////////////////
// �֐��v���g�^�C�v�錾
/////////////////////////////////////////////////////////////////////////////////////
void ballUpdateReset();
void ballUpdateAlive();

/// <summary>
/// �{�[��������
/// </summary>
void BallInit();

/// <summary>
/// �{�[���X�V�@�P�t���[�����Ƃ̍X�V
/// </summary>
/// <param name="deltaTime">1�t���[�����̏�������</param>
void BallUpdate();

/// <summary>
/// �{�[���o��
/// </summary>
void BallDraw();

/// <summary>
/// �{�[���폜
/// </summary>
void BallFinalize();

/// <summary>
/// �{�[����Y = MAX�̈ʒu���ǂ���
/// </summary>
bool SCREEN_YMaxHitCheck();
