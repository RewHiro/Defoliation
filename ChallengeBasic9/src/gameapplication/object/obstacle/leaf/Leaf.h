#pragma once
#include "../Obstacle.h"
#include "../../../scene/Scene.h"
#include "../../../utility/CRandom.h"

class CLeaf : public CObstacle{
public:
	CLeaf();

	void Update();

	void Draw();

	enum TYPE{
		ONE,
		TWO,
		DUO,
		RED
	};
	Texture leaf_tex;

	int Type;
	float angle;

	Vec2f ang_s;


	static int type;

	float radius = 50;

	std::shared_ptr<AppEnv> m_app_env;

	Vec2f m_pos;

	bool m_hit_tap = false;
	Vec2f set_point;
	//	“_‚Æ‰~‚Ì“–‚½‚è”»’è
	bool Check(Vec2f pos, Vec2f obj_pos, float  radius)
	{
		if ((pos.x() - obj_pos.x())*(pos.x() - obj_pos.x()) + (pos.y() - obj_pos.y()) * (pos.y() - obj_pos.y()) <= radius*radius)
		{
			return true;
		}
		else return false;
	}

	//	—”‚ð—p‚¢‚ÄˆÊ’u‚ðŒˆ‚ß‚é
	Vec2f SetPoint(){
		return Vec2f(Vec2f(m_random.Uniform(-CScene::WIDTH / 2 + m_model.GetScaleX(), CScene::WIDTH / 2 - m_model.GetScaleX()),
			m_random.Uniform(-CScene::HEIGHT / 2 + m_model.GetScaleY(), CScene::HEIGHT / 2 - m_model.GetScaleY() - 100)));
	}

	void Hit();

	void Move();
	void LoadGraphics();
	CObjectInfoManager m_info;
	CRandom& m_random;
};

