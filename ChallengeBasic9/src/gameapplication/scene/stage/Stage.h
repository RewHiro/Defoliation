#pragma once
#include "../Scene.h"
#include "../../resource/Resource.h"
#include "../../task/ObjectTask.h"
#include <chrono>
#include <memory>
#include "../../utility/Font.h"

//========================================
//ステージクラス
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env);

	//　更新
	Type Update();

	//　描画
	void Draw();

	static int m_enemy_swipe_count;
	static int m_enemy_tap_count;
	static int m_sweetopotato_swipe_count;
	static int m_sweetopotato_tap_count;
	static int m_holyghost_swipe_count;
	static int m_holyghost_tap_count;
	static int m_stage_num;										//　現在のステージ数

private:
	CObjectTask m_obj_task;

	enum class Digit{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE
	};

	const int ReadyCenterPosX;								//　レディーの真ん中のポジション
	bool isRemove;											//　削除するかどうか
	bool isReady;											//　準備中か
	bool isFinish;											//　終了したか
	bool isDescription = true;
	int m_count;											//　フレームカウント
	int m_ready_count;										//　レディーのカウント
	int m_hi_combo_num;
	int m_combo_num;




	Vec2f m_ready_pos;										//　レディーのポジション
	Vec2f m_finish_pos;										//　フィニッシュのポジション
	std::array<int, 3>m_time_digit;							//　時間の桁
	std::array<std::unique_ptr<Font>, 3>m_time_graph;		//　時間の表示
	std::chrono::seconds m_time;							//　時間
	std::array<int, 5>m_score_digit;							//　スコアの桁
	std::array<std::unique_ptr<Font>, 5>m_score_num_graph;	//　スコアの数字表示
	std::unique_ptr<Font>m_score_graph;						//　スコアの表示
	std::unique_ptr<Font>m_stage_graph;						//　ステージの文字表示
	std::unique_ptr<Font>m_stage_num_graph;					//　ステージの文字表示
	std::unique_ptr<Font>m_combo_graph;						//　コンボの文字表示
	std::unique_ptr<Font>m_combo_num_graph;					//　コンボ数の表示
	std::unique_ptr<Font>m_ready_graph;						//　レディーの表示
	std::unique_ptr<Font>m_finish_graph;					//　フィニッシュの表示
	std::unique_ptr<Font>m_font_des;					//　フィニッシュの表示


	//　操作
	void Control();

	//　制限時間の処理
	void TimeUpdate();

	//　時間が減少する処理
	void AddCount();

	//　時間の描画
	void TimeDraw();

	//　桁の処理
	void TimeDigitUpdate();

	//　時間の更新
	void ToLoseTime();

	//　スコアの数字描画
	void ScoreNumDraw();

	//　スコアの更新
	void ScoreUpdate();

	//　スコアの文字描画
	void ScoreStringDraw();

	//　ステージの文字描画
	void StageStringDraw();

	//　ステージ数の更新
	void StageNumUpdate();

	//　コンボの文字描画
	void ComboStringDraw();

	//　遷移処理
	void Transition();

	//　準備の処理
	void Ready();

	//　準備後の処理
	void UpdateOfAfterReady();

	//　準備の描画
	void ReadyStringDraw();

	//　レディの移動処理
	void MoveReadyStirng();

	//　準備の処理
	void Finish();

	//　準備の描画
	void FinishStringDraw();

	//　レディの移動処理
	void MoveFinishStirng();

	//　終了処理
	void Finalize();

	//　ヒットカウントの初期化
	void HitCountClear();

	//　ハイコンボの処理
	void Combo();

};

