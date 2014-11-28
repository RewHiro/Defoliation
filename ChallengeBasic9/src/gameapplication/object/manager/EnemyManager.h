#pragma once
#include "ObjectManager.h"
#include "../regist/ObjectRegist.h"
#include "../factory/EnemyFactory.h"

//========================================
//�v���C���[�Ǘ��N���X
//========================================

class CEnemyManager : public CObjectManager{
public:
	CEnemyManager::CEnemyManager(){
		m_info_manager(InfoType::ENMEY).GetInfo(InfoType::ENMEY).Regist(m_obj_regist);
	}

	void Update();
private:

	void Create();
	CEnemyFactory m_factory;
};

