#include "ImplantManager.h"


CImplantManager::CImplantManager(){
	Regist(L"芋", m_factory.Getobject(CImplantFactory::Type::SWEETOPOTAO));
	Regist(L"神様", m_factory.Getobject(CImplantFactory::Type::HOLYGHOST));
	m_info_manager(InfoType::IMPLANT).GetInfo(InfoType::IMPLANT).Regist(m_obj_regist);
}


void CImplantManager::Update(){
	CObjectManager::Update();
	Create();
}
void CImplantManager::Create(){
	if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"芋") == 0){
		if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"神様") == 0){
			Regist(L"神様", m_factory.Getobject(CImplantFactory::Type::HOLYGHOST));
		}
	}
	if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"芋") == 0){
		Regist(L"芋", m_factory.Getobject(CImplantFactory::Type::SWEETOPOTAO));
	}

}