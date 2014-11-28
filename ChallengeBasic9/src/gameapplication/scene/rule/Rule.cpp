#include "Rule.h"


CRule::CRule(std::shared_ptr<AppEnv>app_env) :
CScene(app_env)
{
	m_change_scene = Type::RULE;
}

//@XV
CScene::Type CRule::Update(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
	}
	return m_change_scene;
}

void CRule::Draw(){

}
