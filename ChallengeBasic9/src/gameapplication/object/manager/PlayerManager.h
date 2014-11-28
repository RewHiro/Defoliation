#pragma once
#include "ObjectManager.h"
#include "../regist/ObjectRegist.h"
#include "../factory/PlayerFactory.h"

//========================================
//プレイヤー管理クラス
//========================================

class CPlayerManager : public CObjectManager{
public:
	CPlayerManager::CPlayerManager(std::shared_ptr<AppEnv>app_env){
		Regist(L"プレイヤー", m_factory.Getobject(CPlayerFactory::Type::PLAYER, app_env));
		m_info_manager(InfoType::PLAYER).GetInfo(InfoType::PLAYER).Regist(m_obj_regist);
	}
private:
	CPlayerFactory m_factory;
};

