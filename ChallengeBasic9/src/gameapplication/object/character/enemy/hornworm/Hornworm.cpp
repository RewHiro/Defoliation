#include "Hornworm.h"
#include "../../../../scene/stage/Stage.h"
#include "../../player/Player.h"
#include "../../../../utility/Collision.h"

CHornworm::CHornworm() :
count(0),
press_count(0),
push_count(0),
flag(0),
move_flag(1),
ADD_SCORE(500),
DIFF_SCORE(-500),
m_isswipe(false),
m_istap(false),
m_random(CRandom::GetInstance())
{
	m_model.Scaling(Vec2f(128, 128));

	m_model.Position(Vec2f(m_random.Uniform(-CScene::WIDTH / 2 + m_model.GetScaleX(), CScene::WIDTH / 2 - m_model.GetScaleX()),
		m_random.Uniform(-CScene::HEIGHT / 2 + m_model.GetScaleY(), CScene::HEIGHT / 2 - m_model.GetScaleY() - 100)));

	m_hit_model = m_model;
	m_hit_model.Scaling(Vec2f(32, 32));
}


//�@�X�V
void CHornworm::Update(){
	count += 1;

	if (flag == 0 && count % 200 == 0)move_flag *= -1;
	if (flag == 0 && move_flag == 1)m_model.Translate(0.5f, 0);
	if (flag == 0 && move_flag == -1)m_model.Translate(-0.5f, 0);
	if (m_model.GetPosX() <= -CScene::WIDTH / 2)move_flag = 1;
	if (m_model.GetPosX() >= CScene::WIDTH / 2 + 128)move_flag = -1;
	m_hit_model.Position(Vec2f(m_model.GetPosX(),m_model.GetPosY()-20));
	hit();
	Remove();
}

//�@�`��
void CHornworm::Draw(){

	if (flag == 0 && m_hit_tap){
		m_istap = true;
		flag = 1;
	}
	if (flag == 1){
		push_count += 1;
		drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), m_model.GetScaleX(), m_model.GetScaleY(), 0, 0, m_model.GetScaleX(), m_model.GetScaleY(), m_res.GetEnemy(ENEMY_GRAPH::HORNWORN_DEATH), Color(1, 1, 1), 0, Vec2f(1, 1), Vec2f(m_model.GetScaleX() / 2, m_model.GetScaleY() / 2));
		if (push_count == 40){
			m_is_delete = true;
			//m_is_active = false;
		}
	}

	if (!m_is_hit){
		if (m_hit_tap){
			for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
				auto score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(ADD_SCORE + score);
				m_is_hit = true;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransoformCombo(1);
			}
		}
		if (flag == 2 && press_count == 1){
			for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
				auto score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(DIFF_SCORE + score);
				if (DIFF_SCORE + score < 0){
					m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->TransformOfScore(0);
					m_is_hit = true;
					m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->ComboClear();
					m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->ControlFalse();
				}
			}
		}
	}


	if (flag == 0 && m_hit_swipe){
		m_isswipe = true;
		flag = 2;
	}

	if (flag == 2){
		press_count += 1;
		if (press_count % 3 == 0){
			m_model.Translate(m_random.Uniform(-5, 5), m_random.Uniform(-5, 5));
		}
		if (press_count == 60){
			m_is_delete = true;
			//m_pos.x() = CRandom::Uniform(-CScene::WIDTH / 2, CScene::WIDTH / 2 - 128);
			//m_pos.y() = CRandom::Uniform(-CScene::HEIGHT / 2, CScene::HEIGHT / 2 - 128);
			//press_count = 0;
			//flag = 0;
		}
	}


	if (move_flag == 1 && flag == 0 || move_flag == 1 && flag == 2){
		drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), m_model.GetScaleX(), m_model.GetScaleY(), 0, 0, m_model.GetScaleX(), m_model.GetScaleY(), m_res.GetEnemy(ENEMY_GRAPH::HORNWORN), Color(1, 1, 1), 0, Vec2f(1, 1), Vec2f(m_model.GetScaleX()/2, m_model.GetScaleY()/2));
	}
	if (move_flag == -1 && flag == 0 || move_flag == -1 && flag == 2){
		drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), m_model.GetScaleX(), m_model.GetScaleY(), m_model.GetScaleX(), 0, -m_model.GetScaleX(), m_model.GetScaleY(), m_res.GetEnemy(ENEMY_GRAPH::HORNWORN), Color(1, 1, 1), 0, Vec2f(1, 1), Vec2f(m_model.GetScaleX() / 2, m_model.GetScaleY() / 2));
	}
	//drawCircle(m_hit_model.GetPosX(), m_hit_model.GetPosY(), m_hit_model.GetScaleX(), m_hit_model.GetScaleY(), 20, 5, Color(1, 1, 1));
}

//�@�����蔻��
void CHornworm::hit(){
	if (m_hit_tap || m_hit_swipe)return;
	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		auto player_pos = m_info.GetInfo(InfoType::PLAYER).GetPos(it);
		auto score = m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->GetScore();
		if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isTap()){
			if (Collision::CircleAndPoint(m_hit_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_hit_tap = true;
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->HitClear();
				CStage::m_enemy_tap_count++;
			}
		}
		else if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isSwipe()){
			if (Collision::CircleAndPoint(m_model.GetPos(), m_hit_model.GetScaleX(), player_pos)){
				m_hit_swipe = true;
				CStage::m_enemy_swipe_count++;
			}
		}
	}
	return;

}

void CHornworm::Remove(){
	if (m_is_active)return;
	m_is_delete = true;
}

void CHornworm::Acctive(){

}