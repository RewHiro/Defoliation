#pragma once
#include "../Character.hpp"
#include "../../../resource/Resource.hpp"

class CEnemy : public CCharacter{
public:
	CEnemy(std::shared_ptr<AppEnv>app_env, std::vector<std::shared_ptr<Object>>obj_list);

	//　更新
	void Update();

	//　描画
	void Draw();

private:
	int touch;
	int count;
	int press_count;
	int push_count;
	int flag;
	int move_flag;

	std::vector<std::shared_ptr<Object>>m_obj_list;
	CResource& m_res;
	int hit(Vec2f& point_pos);
};

