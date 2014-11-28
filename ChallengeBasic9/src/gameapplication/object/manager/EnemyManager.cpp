#include "EnemyManager.h"

void CEnemyManager::Update(){
	CObjectManager::Update();
	Create();
}

void CEnemyManager::Create(){
	if (m_info_manager.GetInfo(InfoType::ENMEY).GetEmpty()){
		Regist(L"�ђ�", m_factory.Getobject(CEnemyFactory::Type::Hornworm));
	}
}