#pragma once
#include "../SceneManager.hpp"
#include <memory>

class CResult : public CScene{
public:
	CResult(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	Type Update();

	//�@�`��
	void Draw();

private:
	std::unique_ptr<Font>m_font;					//�@�t�H���g

	//�@����
	void Control();
};

