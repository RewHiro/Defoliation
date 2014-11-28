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

	//　スモークエフェクト
	void Smoke();

	//　スモーク描画
	void SmokeDraw();
};

