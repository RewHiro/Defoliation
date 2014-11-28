#include "Player.h"
#include "../enemy/Enemy.h"

CPlayer::CPlayer(std::shared_ptr<AppEnv>app_env):
m_app_env(app_env),
m_random(CRandom::GetInstance()),
m_score(0),
m_combo_num(-1),
is_tap(false),
is_swipe(false),
m_is_control(true),
m_control_count(0)
{
	m_model.Position(Vec2f(0,0));
	m_model.Scaling(Vec2f(128, 128));
}

//　更新
void CPlayer::Update(){
	if (!m_is_active)return;
	Control();
	ComboUpdate();
	Bited();
}

//　描画
void CPlayer::Draw(){
	if (!m_is_active)return;
	drawTextureBox(m_model.GetPosX() - m_model.GetScaleX() / 2, m_model.GetPosY() - m_model.GetScaleY() / 2, m_model.GetScaleX(), m_model.GetScaleY(),
		0, 0, 512, 512,
		m_res.GetPlayer(PLAYER_GRAPH::PLAYER), Color(1, 1, 1));
}

//　コンボの更新
void CPlayer::ComboUpdate(){
	if (!m_is_active)return;
}

//　芋のコンボ更新
void CPlayer::UpdateComboOfSweetpotato(){
	//for (auto it = m_obj_list.begin(); it != m_obj_list.end(); it++){
	//	if ((*it)->GetType() == Type::SweetPotato){
	//		if (((*it)->GetisActive()))return;
	//		if (std::dynamic_pointer_cast<CSweetPotato>(*it)->GetisSwipe()){
	//			m_combo_num = -1;
	//		}
	//		else{
	//			m_combo_num++;
	//		}
	//	}
	//}
}

//　神様のコンボ更新
void CPlayer::UpdateComboOfHolyghost(){
	//for (auto it = m_obj_list.begin(); it != m_obj_list.end(); it++){
	//	if ((*it)->GetType() == Type::HolyGhost){
	//		if (((*it)->GetisActive()))return;
	//		if (std::dynamic_pointer_cast<CHolyGhost>(*it)->GetisSwipe()){
	//			m_combo_num = -1;
	//		}
	//		else{
	//			m_combo_num++;
	//		}
	//	}
	//}
}

//　操作
void CPlayer::Control(){
	if (!m_is_control)return;
	m_model.Position(m_app_env.lock()->mousePosition());

	is_swipe = (m_app_env.lock()->isPressButton(Mouse::LEFT) ? true : false);

	is_tap = (m_app_env.lock()->isPushButton(Mouse::LEFT) ? true : false);
}

void CPlayer::Bited(){
	if (m_is_control)return;
	m_control_count++;
	m_model.Translate(m_random.Uniform(-5, 5), m_random.Uniform(-5, 5));
	if (m_control_count == 80){
		m_is_control = true;
		m_control_count = 0;
	}
}