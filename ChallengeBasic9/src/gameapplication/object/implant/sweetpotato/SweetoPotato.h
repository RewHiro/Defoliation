#pragma once
#include "../Implant.h"
#include "../../../utility/Font.h"
#include "../../../utility/CRandom.h"
#include "../../info/ObjectInfoManager.h"

class CSweetoPotato : public CImplant{
public:
	CSweetoPotato();

	void Update();

	void Draw();

	bool GetisSwipe(){ return m_hit_swipe; }
	bool GetisTap(){ return m_hit_tap; }


private:
	const int ADD_SCORE;
	const int DIFF_SCORE;
	const int EFFECT_SPEED;
	int start_effect_count;
	int effect_anime;

	bool m_hit_tap;
	bool m_hit_swipe;
	bool m_is_effect;

	float m_effect_angle;
	Vec2f m_effect_move_pos;
	Vec2f m_effect_vec_pos;

	CRandom& m_random;
	CObjectInfoManager m_info;


	//�@�����������̏���
	void isHit();

	//�@�^�b�v�����Ƃ��̏���
	void UpdateOfTap();

	//�@�X���C�v�����Ƃ��̏���
	void UpdateOfSwaipe();

	//�@�폜
	void Remove();


	//�@�_�l�̕`��
	void HolyGhostDraw();

	//�@�A�N�e�B�u�ȏ�Ԃ̏���
	void Acctive();

	//�@�X���[�N�G�t�F�N�g
	void Smoke();

	//�@�X���[�N�`��
	void SmokeDraw();
};

