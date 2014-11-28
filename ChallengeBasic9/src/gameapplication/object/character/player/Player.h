#pragma once
#include "../Character.h"
#include "../../info/ObjectInfoManager.h"
#include "../../../utility/CRandom.h"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�X�R�A���擾
	int GetScore(){ return m_score; }

	//�@�X�R�A�̕ύX
	void TransformOfScore(int score){ m_score = score; }

	//�@�R���{�����擾
	int GetCombo(){ return m_combo_num; }

	//�@�R���{�����擾
	void ComboClear(){ m_combo_num = -1; }

	//�@�R���{�����擾
	void TransoformCombo(int value){  m_combo_num += value; }

	bool isTap()const{ return is_tap; }

	bool isSwipe()const{ return is_swipe; }

	void HitClear(){ is_tap = false; }

	void ControlFalse(){ m_is_control = false; }

private:
	std::weak_ptr<AppEnv>m_app_env;
	CObjectInfoManager m_info;
	CRandom& m_random;
	int m_score;														//�@�X�R�A
	int m_combo_num;													//�@�R���{

	bool is_tap;														//�@�^�b�v�t���O
	bool is_swipe;														//�@�X���C�v�t���O
	bool m_is_control;
	int m_control_count;
	//�@�R���{�̍X�V
	void ComboUpdate();

	//�@���̃R���{�X�V
	void UpdateComboOfSweetpotato();

	//�@�_�l�̃R���{�X�V
	void UpdateComboOfHolyghost();

	//�@����
	void Control();

	//�@���܂ꂽ�Ƃ��̏���
	void Bited();
};

