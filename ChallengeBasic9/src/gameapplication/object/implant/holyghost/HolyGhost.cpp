#include "HolyGhost.h"
#include "../../../scene/stage/Stage.h"
#include "../../../utility/Collision.h"
#include "../../character/player/Player.h"

CHolyGhost::CHolyGhost() :
ADD_SCORE(1000),
DIFF_SCORE(-500),
ADD_TIME(10),
DIFF_TIME(-10),
m_hit_tap(false),
m_hit_swipe(false),
m_random(CRandom::GetInstance())
{
	m_model.Scaling(Vec2f(64, 64));

	m_model.Position(Vec2f(m_random.Uniform(-CScene::WIDTH / 2 + m_model.GetScaleX(), CScene::WIDTH / 2 - m_model.GetScaleX()),
		m_random.Uniform(-CScene::HEIGHT / 2 + m_model.GetScaleY(), CScene::HEIGHT / 2 - m_model.GetScaleY() - 100)));


	m_hit_model = m_model;
	m_hit_model.Scaling(Vec2f(32, 32));


}

//　更新
void CHolyGhost::Update(){
	Remove();
	Acctive();
}

//　描画
void CHolyGhost::Draw(){
	HolyGhostDraw();
}

void CHolyGhost::isHit(){
	if (m_hit_tap || m_hit_swipe)return;
	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		auto player_pos = m_info.GetInfo(InfoType::PLAYER).GetPos(it);
		auto score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
		if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isTap()){
			if (Collision::CircleAndPoint(m_hit_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(ADD_SCORE+score);
				m_hit_tap = true;
				CStage::m_holyghost_tap_count++;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransoformCombo(1);
			}
		}
		else if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isSwipe()){
			if (Collision::CircleAndPoint(m_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(DIFF_SCORE + score);
				if (DIFF_SCORE + score < 0){
					m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(0);
				}
				m_hit_swipe = true;
				CStage::m_holyghost_swipe_count++;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->ComboClear();
			}
		}
	}
	return;
}

//　タップしたときの処理
void CHolyGhost::UpdateOfTap(){
	if (!m_hit_tap)return;
	m_res.GetSE(SE::HIT01)->play();
	m_is_active = false;
}

//　スワイプしたときの処理
void CHolyGhost::UpdateOfSwaipe(){
	if (!m_hit_swipe)return;
	m_res.GetSE(SE::HIT02)->play();
	m_is_active = false;
}



//　削除
void CHolyGhost::Remove(){
	if (m_is_active)return;
	m_is_delete = true;
}

void CHolyGhost::HolyGhostDraw(){
	if (!m_is_active)return;

	drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), m_model.GetScaleX(), m_model.GetScaleY(),
		0, 0, 256, 256,
		m_res.GetImplant(IMPLANT_GRAPH::HOLYGHOST), Color(1, 1, 1), 0, Vec2f(1, 1), Vec2f(m_model.GetScaleX() / 2, m_model.GetScaleY() / 2));

	//drawCircle(m_hit_model.GetPosX(), m_hit_model.GetPosY(),
	//	m_hit_model.GetScaleX(), m_hit_model.GetScaleY(),
	//	30, 5, Color(1, 0, 0));
}

//　アクティブな状態の処理
void CHolyGhost::Acctive(){
	if (!m_is_active)return;
	isHit();
	UpdateOfTap();
	UpdateOfSwaipe();
}