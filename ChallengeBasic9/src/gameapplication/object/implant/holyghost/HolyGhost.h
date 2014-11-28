#pragma once
#include "../Implant.h"
#include "../../../utility/Font.h"
#include "../../../utility/CRandom.h"
#include "../../info/ObjectInfoManager.h"
#include <chrono>

class CHolyGhost : public CImplant{
public:
	CHolyGhost();

	void Update();

	void Draw();

	bool GetisTap(){ return m_hit_tap; }

	bool GetisSwipe(){ return m_hit_swipe; }

private:
	const int ADD_SCORE;
	const int DIFF_SCORE;
	const std::chrono::seconds ADD_TIME;
	const std::chrono::seconds DIFF_TIME;
	
	bool m_hit_tap;
	bool m_hit_swipe;

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
};

