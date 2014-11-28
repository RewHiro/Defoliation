#include "Leaf.h"
#include "../../../utility/Collision.h"
#include "../../character/player/Player.h"

CLeaf::CLeaf():
m_random(CRandom::GetInstance()),
set_point(Vec2f(0, 0))
{
	angle = m_random.Uniform(0.0f, 50.0f);
	Type = m_random.Uniform(0.0f, 4.0f);


	switch (Type)
	{
	case TYPE::ONE:
		leaf_tex = m_res.GetObstacle(OBSTACLE_GRAPH::LEAF01);
		break;
	case TYPE::TWO:
		leaf_tex = m_res.GetObstacle(OBSTACLE_GRAPH::LEAF02);
		break;
	case TYPE::DUO:
		leaf_tex = m_res.GetObstacle(OBSTACLE_GRAPH::LEAF03);
		break;
	case TYPE::RED:
		leaf_tex = m_res.GetObstacle(OBSTACLE_GRAPH::LEAF04);
		break;
	}
	m_model.Position(SetPoint());

}


void CLeaf::Update(){
	Hit();
}

void CLeaf::Draw(){
	drawTextureBox(m_model.GetPosX(), m_model.GetPosY(), 100, 100,
		0, 0, 256, 256,
		leaf_tex,
		Color(1, 1, 1),
		angle,
		Vec2f(1, 1),
		Vec2f(50, 50));

	//drawCircle(m_model.GetPosX(), m_model.GetPosY(), 50, 50, 100, 1, Color(1, 1, 1));

}

void CLeaf::Hit(){
	for (auto it = m_info.GetInfo(InfoType::PLAYER).Begin(); it != m_info.GetInfo(InfoType::PLAYER).End(); it++){
		auto player_pos = m_info.GetInfo(InfoType::PLAYER).GetPos(it);
		if (m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->isTap()){
			if (Collision::CircleAndPoint(m_model.GetPos(), 50, player_pos)){
				m_model.Position(500, 500);
				m_info.GetInfo(InfoType::PLAYER).DynamicCast<CPlayer>(it)->HitClear();
			}
		}
	}
}