#include "SweetoPotato.h"
#include "../../../scene/stage/Stage.h"
#include "../../../utility/Collision.h"
#include "../../character/player/Player.h"

CSweetoPotato::CSweetoPotato() :
ADD_SCORE(1000),
DIFF_SCORE(500),
EFFECT_SPEED(3),
start_effect_count(0),
effect_anime(0),
m_effect_angle(0),
m_hit_tap(false),
m_hit_swipe(false),
m_is_effect(false),
m_random(CRandom::GetInstance())
{
	m_model.Scaling(Vec2f(64, 64));

	m_model.Position(Vec2f(m_random.Uniform(-CScene::WIDTH / 2 + m_model.GetScaleX(), CScene::WIDTH / 2 - m_model.GetScaleX()),
		m_random.Uniform(-CScene::HEIGHT / 2 + m_model.GetScaleY(), CScene::HEIGHT / 2 - m_model.GetScaleY() - 100)));
	m_res.GetSE(SE::HIT01)->gain(2.0);

	m_hit_model = m_model;
	m_hit_model.Scaling(Vec2f(32, 32));

	m_effect_move_pos = Vec2f(0, 0);
	m_effect_vec_pos = Vec2f(0, 5);
}

//　更新
void CSweetoPotato::Update(){
	Remove();
	Acctive();
}

//　描画
void CSweetoPotato::Draw(){
	HolyGhostDraw();
}

void CSweetoPotato::isHit(){
	if (m_hit_tap || m_hit_swipe)return;
	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		auto player_pos = m_info.GetInfo(InfoType::PLAYER).GetPos(it);
		auto score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
		if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isTap()){
			if (Collision::CircleAndPoint(m_hit_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_hit_tap = true;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(ADD_SCORE + score);
				CStage::m_sweetopotato_tap_count++;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransoformCombo(1);
				CStage::m_stage_num++;
			}
		}
		else if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isSwipe()){
			if (Collision::CircleAndPoint(m_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_hit_swipe = true;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(DIFF_SCORE + score);
				CStage::m_sweetopotato_swipe_count++;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->ComboClear();
				CStage::m_stage_num++;
			}
		}
	}
	return;
}

//　タップしたときの処理
void CSweetoPotato::UpdateOfTap(){
	if (!m_hit_tap)return;
	m_res.GetSE(SE::HIT01)->play();
	m_is_active = false;
}

//　スワイプしたときの処理
void CSweetoPotato::UpdateOfSwaipe(){
	if (!m_hit_swipe)return;
	m_res.GetSE(SE::HIT01)->play();
	m_is_active = false;
}



//　削除
void CSweetoPotato::Remove(){
	if (m_is_active)return;
	m_is_delete = true;
}

void CSweetoPotato::HolyGhostDraw(){
	if (!m_is_active)return;

	drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), m_model.GetScaleX(), m_model.GetScaleY(),
		0, 0, 512, 512,
		m_res.GetImplant(IMPLANT_GRAPH::SWEETOPOTATO), Color(1, 1, 1), 0, Vec2f(1, 1), Vec2f(m_model.GetScaleX() / 2, m_model.GetScaleY() / 2));
	SmokeDraw();
	//drawCircle(m_hit_model.GetPosX(), m_hit_model.GetPosY(),
	//	m_hit_model.GetScaleX(), m_hit_model.GetScaleY(),
	//	30, 5, Color(1, 0, 0));
}

//　アクティブな状態の処理
void CSweetoPotato::Acctive(){
	if (!m_is_active)return;
	isHit();
	UpdateOfTap();
	UpdateOfSwaipe();
	Smoke();
}

void CSweetoPotato::Smoke(){
	start_effect_count++;
	if (start_effect_count < 60*6)return;
	m_is_effect = true;
	m_effect_move_pos += m_effect_vec_pos;
	if (m_model.GetPosY() + m_effect_move_pos.y() > m_model.GetPosY() + 50){
		switch (effect_anime){
		case 0:
			m_effect_vec_pos = Vec2f(0, EFFECT_SPEED);
			m_effect_angle = 0;
			effect_anime = 1;
			break;
		case 1:
			m_effect_vec_pos = Vec2f(-EFFECT_SPEED, EFFECT_SPEED);
			m_effect_angle = static_cast<float>(-M_PI/6);
			effect_anime = 2;
			break;
		case 2:
			m_effect_vec_pos = Vec2f(EFFECT_SPEED, EFFECT_SPEED);
			m_effect_angle = static_cast<float>(M_PI / 6);
			effect_anime = 0; 
			break;
		}
		m_effect_move_pos = Vec2f(0, 0);
	}
}

void CSweetoPotato::SmokeDraw(){
	if (!m_is_effect)return;
	drawTextureBox(m_model.GetPosX() + m_effect_move_pos.x(), m_model.GetPosY() + m_effect_move_pos.y(), 32, 32,
		0, 0, 256, 256,
		m_res.GetImplant(IMPLANT_GRAPH::SMOKE), Color(1, 1, 1),
		m_effect_angle, Vec2f(1, 1), Vec2f(16, 16));
}