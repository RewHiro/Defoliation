#pragma once
#include "../SceneManager.hpp"
#include <memory>

class CRanking : public CScene{
public:
	CRanking(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	Type Update();

	//�@�`��
	void Draw();
private:
	std::unique_ptr<Font>m_font;

	//�@����
	void Control();

};

