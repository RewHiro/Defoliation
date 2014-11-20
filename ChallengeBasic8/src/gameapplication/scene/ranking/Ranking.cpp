#include "Ranking.hpp"


CRanking::CRanking(std::shared_ptr<AppEnv>app_env) :
CScene(app_env),
m_font(std::make_unique<Font>(90))
{
	m_change_scene = Type::RANKING;
}

//�@�X�V
CScene::Type CRanking::Update(){
	Control();
	return m_change_scene;
}

//�@�`��
void CRanking::Draw(){
	m_font->DrawCenter(L"�����L���O���", 0, 200, Color(1, 1, 1));
}

//�@����
void CRanking::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
}