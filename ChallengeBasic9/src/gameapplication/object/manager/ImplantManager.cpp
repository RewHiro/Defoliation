#include "ImplantManager.h"


CImplantManager::CImplantManager(){
	Regist(L"��", m_factory.Getobject(CImplantFactory::Type::SWEETOPOTAO));
	Regist(L"�_�l", m_factory.Getobject(CImplantFactory::Type::HOLYGHOST));
	m_info_manager(InfoType::IMPLANT).GetInfo(InfoType::IMPLANT).Regist(m_obj_regist);
}


void CImplantManager::Update(){
	CObjectManager::Update();
	Create();
}
void CImplantManager::Create(){
	if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"��") == 0){
		if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"�_�l") == 0){
			Regist(L"�_�l", m_factory.Getobject(CImplantFactory::Type::HOLYGHOST));
		}
	}
	if (m_info_manager.GetInfo(InfoType::IMPLANT).GetCount(L"��") == 0){
		Regist(L"��", m_factory.Getobject(CImplantFactory::Type::SWEETOPOTAO));
	}

}