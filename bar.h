////////////////�o�[.h////////////////

// ���C�u�������w�b�_�[�t�@�C���ǂݍ���
#pragma once
#include "gamedata.h"

/////////////////////////////////////////////////////////////////////////////////////
// �֐��v���g�^�C�v�錾
/////////////////////////////////////////////////////////////////////////////////////
void barHitCheck();

/// <summary>
/// �o�[������
/// </summary>
void BarInit();

/// <summary>
/// �o�[�X�V�@�P�t���[�����Ƃ̍X�V
/// </summary>
/// <param name="deltaTime">1�t���[�����̏�������</param>
void BarUpdate();

/// <summary>
/// �o�[�o��
/// </summary>
void BarDraw();

/// <summary>
/// �o�[�폜
/// </summary>
void BarFinalize();