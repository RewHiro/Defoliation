#pragma once
#include "../Scene.h"
#include "../../resource/Resource.h"
#include "../../task/ObjectTask.h"
#include <chrono>
#include <memory>
#include "../../utility/Font.h"

//========================================
//�X�e�[�W�N���X
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	Type Update();

	//�@�`��
	void Draw();

	static int m_enemy_swipe_count;
	static int m_enemy_tap_count;
	static int m_sweetopotato_swipe_count;
	static int m_sweetopotato_tap_count;
	static int m_holyghost_swipe_count;
	static int m_holyghost_tap_count;
	static int m_stage_num;										//�@���݂̃X�e�[�W��

private:
	CObjectTask m_obj_task;

	enum class Digit{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE
	};

	const int ReadyCenterPosX;								//�@���f�B�[�̐^�񒆂̃|�W�V����
	bool isRemove;											//�@�폜���邩�ǂ���
	bool isReady;											//�@��������
	bool isFinish;											//�@�I��������
	int m_count;											//�@�t���[���J�E���g
	int m_ready_count;										//�@���f�B�[�̃J�E���g
	int m_hi_combo_num;
	int m_combo_num;




	Vec2f m_ready_pos;										//�@���f�B�[�̃|�W�V����
	Vec2f m_finish_pos;										//�@�t�B�j�b�V���̃|�W�V����
	std::array<int, 3>m_time_digit;							//�@���Ԃ̌�
	std::array<std::unique_ptr<Font>, 3>m_time_graph;		//�@���Ԃ̕\��
	std::chrono::seconds m_time;							//�@����
	std::array<int, 5>m_score_digit;							//�@�X�R�A�̌�
	std::array<std::unique_ptr<Font>, 5>m_score_num_graph;	//�@�X�R�A�̐����\��
	std::unique_ptr<Font>m_score_graph;						//�@�X�R�A�̕\��
	std::unique_ptr<Font>m_stage_graph;						//�@�X�e�[�W�̕����\��
	std::unique_ptr<Font>m_stage_num_graph;					//�@�X�e�[�W�̕����\��
	std::unique_ptr<Font>m_combo_graph;						//�@�R���{�̕����\��
	std::unique_ptr<Font>m_combo_num_graph;					//�@�R���{���̕\��
	std::unique_ptr<Font>m_ready_graph;						//�@���f�B�[�̕\��
	std::unique_ptr<Font>m_finish_graph;					//�@�t�B�j�b�V���̕\��

	//�@����
	void Control();

	//�@�������Ԃ̏���
	void TimeUpdate();

	//�@���Ԃ��������鏈��
	void AddCount();

	//�@���Ԃ̕`��
	void TimeDraw();

	//�@���̏���
	void TimeDigitUpdate();

	//�@���Ԃ̍X�V
	void ToLoseTime();

	//�@�X�R�A�̐����`��
	void ScoreNumDraw();

	//�@�X�R�A�̍X�V
	void ScoreUpdate();

	//�@�X�R�A�̕����`��
	void ScoreStringDraw();

	//�@�X�e�[�W�̕����`��
	void StageStringDraw();

	//�@�X�e�[�W���̍X�V
	void StageNumUpdate();

	//�@�R���{�̕����`��
	void ComboStringDraw();

	//�@�J�ڏ���
	void Transition();

	//�@�����̏���
	void Ready();

	//�@������̏���
	void UpdateOfAfterReady();

	//�@�����̕`��
	void ReadyStringDraw();

	//�@���f�B�̈ړ�����
	void MoveReadyStirng();

	//�@�����̏���
	void Finish();

	//�@�����̕`��
	void FinishStringDraw();

	//�@���f�B�̈ړ�����
	void MoveFinishStirng();

	//�@�I������
	void Finalize();

	//�@�q�b�g�J�E���g�̏�����
	void HitCountClear();

	//�@�n�C�R���{�̏���
	void Combo();

};

