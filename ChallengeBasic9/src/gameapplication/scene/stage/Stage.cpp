#include "Stage.h"
#include "../SceneManager.h"
#include "../../object/character/player/Player.h"
#include "../../object/character/enemy/Enemy.h"
#include "../../object/manager/PlayerManager.h"
#include "../../object/manager/EnemyManager.h"
#include "../../object/manager/ImplantManager.h"
#include "../../object/manager/ObstacleManager.h"
#include <fstream>

int CStage::m_enemy_swipe_count = 0;
int CStage::m_enemy_tap_count = 0;
int CStage::m_sweetopotato_swipe_count = 0;
int CStage::m_sweetopotato_tap_count = 0;
int CStage::m_holyghost_swipe_count = 0;
int CStage::m_holyghost_tap_count = 0;
int CStage::m_stage_num = 1;

CStage::CStage(std::shared_ptr<AppEnv>app_env) :
CScene(app_env),
ReadyCenterPosX(-80),
isRemove(false),
isReady(true),
isFinish(false),
m_count(0),
m_ready_count(0),
m_ready_pos(Vec2f(CScene::WIDTH / 2 + 100, 0)),
m_finish_pos(Vec2f(CScene::WIDTH / 2 + 150, 0)),
m_time(30),
m_combo_num(0)
{
	m_res.GetSE(SE::HIT01)->gain(2.0);
	m_change_scene = Type::STAGE;
	m_res.GetBGM(BGM::STAGE)->looping(true);
	m_res.GetBGM(BGM::STAGE)->play();
	m_obj_task.Regist(1, std::make_unique<CPlayerManager>(app_env));
	m_obj_task.Regist(3, std::make_unique<CEnemyManager>());
	m_obj_task.Regist(4, std::make_unique<CImplantManager>());
	m_obj_task.Regist(2, std::make_unique<CObstacleManager>());
	m_stage_num = 1;
	for (auto &font : m_time_graph){
		font = std::make_unique<Font>(60, L"ニコモジ");
	}

	for (auto &font : m_score_num_graph){
		font = std::make_unique<Font>(40, L"ニコモジ");
	}

	m_score_graph = std::make_unique<Font>(40, L"ニコモジ");
	m_stage_graph = std::make_unique<Font>(40, L"ニコモジ");
	m_stage_num_graph = std::make_unique<Font>(40, L"ニコモジ");
	m_combo_graph = std::make_unique<Font>(40, L"ニコモジ");
	m_combo_num_graph = std::make_unique<Font>(40, L"ニコモジ");
	m_ready_graph = std::make_unique<Font>(60, L"Pacifico");
	m_finish_graph = std::make_unique<Font>(60, L"Pacifico");

	m_time_digit[0] = 0;
	m_time_digit[1] = 3;
	m_time_digit[2] = 0;

	for (auto& font : m_score_digit){
		font = 0;
	}
}

//　更新
CScene::Type CStage::Update(){
	Ready();
	Finish();
	StageNumUpdate();
	UpdateOfAfterReady();
	ScoreUpdate();

	TimeDigitUpdate();
	InfoClear(Type::STAGE);
	return m_change_scene;
}

//　描画
void CStage::Draw(){

	drawTextureBox(-CScene::WIDTH / 2, -CScene::HEIGHT / 2, CScene::WIDTH, CScene::HEIGHT, 0, 0, 1024, 512, m_res.GetBG(BG::STAGE), Color(1, 1, 1));
	m_obj_task.Draw();

	TimeDraw();
	ScoreNumDraw();
	ScoreStringDraw();
	StageStringDraw();
	ComboStringDraw();
	ReadyStringDraw();
	FinishStringDraw();
}

//　操作
void CStage::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::RESULT;
		m_res.GetBGM(BGM::STAGE)->stop();
		Finalize();
	}
}

//　制限時間の処理
void CStage::TimeUpdate(){
	AddCount();


	Transition();
}

//　時間が減少する処理
void CStage::AddCount(){
	m_count++;
	ToLoseTime();
}

//　時間の描画
void CStage::TimeDraw(){
	m_time_graph[static_cast<int>(Digit::ONE)]->DrawCenter(std::to_wstring(m_time_digit[0]),
		m_time_graph[0]->GetSize(), CScene::HEIGHT / 2 - m_time_graph[0]->GetSize() / 2,
		color256(102, 51, 255), 3);

	m_time_graph[static_cast<int>(Digit::TWO)]->DrawCenter(std::to_wstring(m_time_digit[1]),
		0, CScene::HEIGHT / 2 - m_time_graph[1]->GetSize() / 2,
		color256(102, 51, 255), 3);

	m_time_graph[static_cast<int>(Digit::THREE)]->DrawCenter(std::to_wstring(m_time_digit[2]),
		-m_time_graph[2]->GetSize(), CScene::HEIGHT / 2 - m_time_graph[2]->GetSize() / 2,
		color256(102, 51, 255), 3);
}

//　	桁の処理
void CStage::TimeDigitUpdate(){

	for (auto it = m_info.GetInfo(InfoType::IMPLANT).Begin(L"神様"); it != m_info.GetInfo(InfoType::IMPLANT).End(L"神様"); it++){
		if (m_info.GetInfo(InfoType::IMPLANT).DynamicCast<CHolyGhost>(it)->GetisTap()){
			m_time += std::chrono::seconds(10);
		}
		else if (m_info.GetInfo(InfoType::IMPLANT).DynamicCast<CHolyGhost>(it)->GetisSwipe()){
			m_time += std::chrono::seconds(-10);
		}
	}
	if (m_time < std::chrono::seconds(0)){
		m_time = std::chrono::seconds(0);
	}
	m_time_digit[static_cast<int>(Digit::ONE)] = m_time.count() % 10;
	m_time_digit[static_cast<int>(Digit::TWO)] = m_time.count() / 10 % 10;
	m_time_digit[static_cast<int>(Digit::THREE)] = m_time.count() / 100;
}

//　時間の更新
void CStage::ToLoseTime(){
	if (!(m_count % 60 == 0))return;

	m_time--;
}

//　スコアの描画
void CStage::ScoreNumDraw(){

	m_score_num_graph[static_cast<int>(Digit::ONE)]->Draw(std::to_wstring(m_score_digit[0]),
		-CScene::WIDTH / 2 + m_score_num_graph[0]->GetSize() * 4 / 1.5, CScene::HEIGHT / 2 - (m_score_num_graph[0]->GetSize() / 1.5) * 2,
		color256(102, 51, 255));

	m_score_num_graph[static_cast<int>(Digit::TWO)]->Draw(std::to_wstring(m_score_digit[1]),
		-CScene::WIDTH / 2 + m_score_num_graph[1]->GetSize() * 3 / 1.5, CScene::HEIGHT / 2 - (m_score_num_graph[1]->GetSize() / 1.5) * 2,
		color256(102, 51, 255));

	m_score_num_graph[static_cast<int>(Digit::THREE)]->Draw(std::to_wstring(m_score_digit[2]),
		-CScene::WIDTH / 2 + m_score_num_graph[2]->GetSize() * 2 / 1.5, CScene::HEIGHT / 2 - (m_score_num_graph[2]->GetSize() / 1.5) * 2,
		color256(102, 51, 255));

	m_score_num_graph[static_cast<int>(Digit::FOUR)]->Draw(std::to_wstring(m_score_digit[3]),
		-CScene::WIDTH / 2 + m_score_num_graph[3]->GetSize() * 1 / 1.5, CScene::HEIGHT / 2 - (m_score_num_graph[3]->GetSize() / 1.5) * 2,
		color256(102, 51, 255));

	m_score_num_graph[static_cast<int>(Digit::FIVE)]->Draw(std::to_wstring(m_score_digit[4]),
		-CScene::WIDTH / 2 + m_score_num_graph[4]->GetSize() * 0 / 1.5, CScene::HEIGHT / 2 - (m_score_num_graph[4]->GetSize() / 1.5) * 2,
		color256(102, 51, 255));

}

//　スコアの更新
void CStage::ScoreUpdate(){
	int score;
	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
	}

	m_score_digit[static_cast<int>(Digit::ONE)] = score % 10;
	m_score_digit[static_cast<int>(Digit::TWO)] = score / 10 % 10;
	m_score_digit[static_cast<int>(Digit::THREE)] = score / 100 % 10;
	m_score_digit[static_cast<int>(Digit::FOUR)] = score / 1000 % 10;
	m_score_digit[static_cast<int>(Digit::FIVE)] = score / 10000;
}

//　スコアの文字描画
void CStage::ScoreStringDraw(){
	m_score_graph->Draw(L"SCORE",
		-CScene::WIDTH / 2, CScene::HEIGHT / 2 - m_score_graph->GetSize() / 1.5,
		color256(102, 51, 255));
}

//　ステージの文字描画
void CStage::StageStringDraw(){
	m_stage_graph->Draw(L"STAGE",
		-CScene::WIDTH / 2, -CScene::HEIGHT / 2,
		color256(102, 51, 255));
	m_stage_num_graph->Draw(std::to_wstring(m_stage_num),
		-CScene::WIDTH / 2 + m_stage_graph->GetSize() * 4, -CScene::HEIGHT / 2,
		color256(102, 51, 255));
}

//　ステージ数の更新
void CStage::StageNumUpdate(){
	//for (auto it = m_info.GetInfo(InfoType::OBSTACLE).Begin(L"芋"); it != m_info.GetInfo(InfoType::OBSTACLE).End(L"芋"); it++){
	//	if (!m_info.GetInfo(InfoType::OBSTACLE).GetActive(it)){
	//		m_stage_num++;
	//	}
	//}

}

//　コンボの文字描画
void CStage::ComboStringDraw(){
	if (m_combo_num <= 0)return;

	m_combo_graph->Draw(L"COMBO!",
		CScene::WIDTH / 2 - m_combo_graph->GetSize() * 9, CScene::HEIGHT / 2 - m_combo_graph->GetSize() * 2,
		color256(102, 51, 255));
	m_combo_num_graph->Draw(std::to_wstring(m_combo_num),
		CScene::WIDTH / 2 - m_combo_graph->GetSize() * 4, CScene::HEIGHT / 2 - m_combo_graph->GetSize() * 2,
		color256(102, 51, 255));

}

//　遷移処理
void CStage::Transition(){
	if (isFinish)return;
	if (m_time.count() <= 0){
		m_time = std::chrono::seconds(0);
		isFinish = true;
		m_res.GetBGM(BGM::STAGE)->stop();
		m_res.GetSE(SE::STAGE_FINISH)->play();
	}
}

//　準備後の処理
void CStage::UpdateOfAfterReady(){
	if (isReady || isFinish)return;
	Control();
	TimeUpdate();
	Combo();
	m_obj_task.Update();
}

//　準備の処理
void CStage::Ready(){
	if (!isReady)return;
	m_ready_count++;
	MoveReadyStirng();
	if (m_ready_count > 300){
		isReady = false;
		m_res.GetSE(SE::STAGE_START)->play();
	}
}

//　レディーの描画
void CStage::ReadyStringDraw(){
	if (!isReady)return;
	m_ready_graph->Draw("Ready",
		m_ready_pos.x(), m_ready_pos.y(),
		color256(102, 51, 255));
}

//　レディーの移動処理
void CStage::MoveReadyStirng(){
	if (!(m_ready_count > 120 && 240 > m_ready_count))return;
	m_ready_pos.x() -= 10;
	if (m_ready_pos.x() < ReadyCenterPosX){
		m_ready_pos.x() = ReadyCenterPosX;
	}
}

//　準備の処理
void CStage::Finish(){
	if (!isFinish)return;
	MoveFinishStirng();
}

//　準備の描画
void CStage::FinishStringDraw(){
	if (!isFinish)return;
	m_finish_graph->Draw("Finish",
		m_finish_pos.x(), m_finish_pos.y(),
		color256(102, 51, 255));
}

//　レディの移動処理
void CStage::MoveFinishStirng(){
	if (isRemove)return;
	m_finish_pos.x() -= 10;
	if (m_finish_pos.x() < ReadyCenterPosX){
		m_finish_pos.x() = ReadyCenterPosX;
		m_change_scene = Type::RESULT;
		isRemove = true;
		Finalize();
	}
}

void CStage::Finalize(){
	std::ofstream save("res/score.txt");
	if (save){
		save << m_sweetopotato_tap_count << std::endl <<
			m_sweetopotato_swipe_count << std::endl <<
			m_enemy_tap_count << std::endl <<
			m_enemy_swipe_count << std::endl <<
			m_holyghost_tap_count << std::endl <<
			m_holyghost_swipe_count << std::endl <<
			m_hi_combo_num;
	}
	HitCountClear();
}

void CStage::HitCountClear(){
	m_enemy_swipe_count = 0;
	m_enemy_tap_count = 0;
	m_sweetopotato_swipe_count = 0;
	m_sweetopotato_tap_count = 0;
	m_holyghost_swipe_count = 0;
	m_holyghost_tap_count = 0;
}

void CStage::Combo(){

	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		auto combo = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetCombo();
		m_combo_num = combo;
		if (m_hi_combo_num < combo){
			m_hi_combo_num = combo;
		}
	}

}