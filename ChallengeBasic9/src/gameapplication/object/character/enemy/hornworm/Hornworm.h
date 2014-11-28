#pragma once
#include "../Enemy.h"
#include "../../../../utility/CRandom.h"
class CHornworm : public CEnemy{
public:
	CHornworm();

	//　更新
	void Update();

	//　描画
	void Draw();

	bool GetisSwipe(){ return m_isswipe; }

private:
	int touch;
	int count;
	int press_count;
	int push_count;
	int flag;
	int move_flag;
	bool m_isswipe;
	bool m_istap;
	bool m_hit_tap = false;
	bool m_hit_swipe = false;
	bool m_is_hit = false;

	const int ADD_SCORE;
	const int DIFF_SCORE;

	CRandom& m_random;
	void hit();

	void Remove();

	void Acctive();
};