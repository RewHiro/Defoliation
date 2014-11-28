#pragma once
#include "../Character.h"
#include "../../info/ObjectInfoManager.h"
#include "../../../utility/CRandom.h"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>);

	//　更新
	void Update();

	//　描画
	void Draw();

	//　スコアを取得
	int GetScore(){ return m_score; }

	//　スコアの変更
	void TransformOfScore(int score){ m_score = score; }

	//　コンボ数を取得
	int GetCombo(){ return m_combo_num; }

	//　コンボ数を取得
	void ComboClear(){ m_combo_num = -1; }

	//　コンボ数を取得
	void TransoformCombo(int value){  m_combo_num += value; }

	bool isTap()const{ return is_tap; }

	bool isSwipe()const{ return is_swipe; }

	void HitClear(){ is_tap = false; }

	void ControlFalse(){ m_is_control = false; }

private:
	std::weak_ptr<AppEnv>m_app_env;
	CObjectInfoManager m_info;
	CRandom& m_random;
	int m_score;														//　スコア
	int m_combo_num;													//　コンボ

	bool is_tap;														//　タップフラグ
	bool is_swipe;														//　スワイプフラグ
	bool m_is_control;
	int m_control_count;
	//　コンボの更新
	void ComboUpdate();

	//　芋のコンボ更新
	void UpdateComboOfSweetpotato();

	//　神様のコンボ更新
	void UpdateComboOfHolyghost();

	//　操作
	void Control();

	//　かまれたときの処理
	void Bited();
};

