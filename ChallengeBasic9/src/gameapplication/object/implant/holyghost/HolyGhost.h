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

	//　当たった時の処理
	void isHit();

	//　タップしたときの処理
	void UpdateOfTap();

	//　スワイプしたときの処理
	void UpdateOfSwaipe();

	//　削除
	void Remove();


	//　神様の描画
	void HolyGhostDraw();

	//　アクティブな状態の処理
	void Acctive();
};

