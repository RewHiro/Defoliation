#include "ObstacleManager.h"


CObstacleManager::CObstacleManager()
{
	for (int i = 0; i < 300; i++){
		Regist(L"���[�t", m_factory.Getobject(CObstacleFactory::Type::LEAF));
	}
	m_info_manager(InfoType::OBSTACLE).GetInfo(InfoType::OBSTACLE).Regist(m_obj_regist);
}
