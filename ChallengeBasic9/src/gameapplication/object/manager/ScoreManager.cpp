#include "ScoreManager.h"
#include "../character/enemy/hornworm/Hornworm.h"
#include "../implant/holyghost/HolyGhost.h"
#include "../implant/sweetpotato/SweetoPotato.h"

CScoreManager::CScoreManager()
{
	m_info_manager(InfoType::SCORE).GetInfo(InfoType::SCORE).Regist(m_obj_regist);
}


void CScoreManager::Update(){
	CObjectManager::Update();
	Create();
}

void CScoreManager::Create(){
	for (auto it = m_info_manager.GetInfo(InfoType::ENMEY).Begin(); it != m_info_manager.GetInfo(InfoType::ENMEY).End(); it++){
		if (m_info_manager.GetInfo(InfoType::ENMEY).DynamicCast<CHornworm>(it)->GetisScore()){
			if (m_info_manager.GetInfo(InfoType::ENMEY).DynamicCast<CHornworm>(it)->GetisTap()){
				auto pos = m_info_manager.GetInfo(InfoType::ENMEY).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::PLUS_SCORE, pos, 500));
				m_info_manager.GetInfo(InfoType::ENMEY).Death(it);
			}
			else if (m_info_manager.GetInfo(InfoType::ENMEY).DynamicCast<CHornworm>(it)->GetisSwipe()){
				auto pos = m_info_manager.GetInfo(InfoType::ENMEY).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::MINUS_SCORE, pos, 500));
				m_info_manager.GetInfo(InfoType::ENMEY).Death(it);
			}
		}
	}

	for (auto it = m_info_manager.GetInfo(InfoType::IMPLANT).Begin(L"神様"); it != m_info_manager.GetInfo(InfoType::IMPLANT).End(L"神様"); it++){
		if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CHolyGhost>(it)->GetisScore()){

			if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CHolyGhost>(it)->GetisTap()){
				auto pos = m_info_manager.GetInfo(InfoType::IMPLANT).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::PLUS_SCORE_TIME, pos, 1000, std::chrono::seconds(10)));
				m_info_manager.GetInfo(InfoType::IMPLANT).Death(it);
			}
			else if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CHolyGhost>(it)->GetisSwipe()){
				auto pos = m_info_manager.GetInfo(InfoType::IMPLANT).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::MAINUS_SCORE_TIME, pos, 1000, std::chrono::seconds(10)));
				m_info_manager.GetInfo(InfoType::IMPLANT).Death(it);

			}
		}
	}

	for (auto it = m_info_manager.GetInfo(InfoType::IMPLANT).Begin(L"芋"); it != m_info_manager.GetInfo(InfoType::IMPLANT).End(L"芋"); it++){
		if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CSweetoPotato>(it)->GetisScore()){
			if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CSweetoPotato>(it)->GetisTap()){
				auto pos = m_info_manager.GetInfo(InfoType::IMPLANT).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::PLUS_SCORE, pos, 1000));
				m_info_manager.GetInfo(InfoType::IMPLANT).Death(it);

			}
			else if (m_info_manager.GetInfo(InfoType::IMPLANT).DynamicCast<CSweetoPotato>(it)->GetisSwipe()){
				auto pos = m_info_manager.GetInfo(InfoType::IMPLANT).GetPos(it);
				Regist(L"スコア", m_factory.Getobject(CScoreFactory::Type::PLUS_SCORE, pos, 500));
				m_info_manager.GetInfo(InfoType::IMPLANT).Death(it);

			}
		}
	}
	
}