#include "Result.hpp"


CResult::CResult(std::shared_ptr<AppEnv>app_env):
CScene(app_env),
m_font(std::make_unique<Font>(60))
{
	m_change_scene = Type::RESULT;
}


//�@�X�V
CScene::Type CResult::Update(){
	Control();
	return m_change_scene;
}

//�@�`��
void CResult::Draw(){
	m_font->DrawCenter(L"���U���g���", 0, 0, Color(1, 1, 1));
}

//�@����
void CResult::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
}