#pragma once
#include "../Object.h"
#include "../info/ObjectInfoManager.h"
#include <unordered_map>
#include <string>


//========================================
//オブジェクト管理クラス(基底クラス)
//========================================

class CObjectManager{
public:
	CObjectManager():
		m_obj_regist(std::make_shared<CObjectRegist>()){}

	virtual ~CObjectManager() = default;

	//　更新
	virtual void Update(){
		for (auto& obj : m_obj_regist->Getobject()){
			obj.second->Update();
		}
		Remove();
	}

	//　描画
	void Draw(){
		for (auto& obj : m_obj_regist->Getobject()){
			obj.second->Draw();
		}
	}

protected:
	CObjectInfoManager m_info_manager;
	std::shared_ptr<CObjectRegist>m_obj_regist;

	//　削除
	void Remove(){
		for (auto it = m_obj_regist->GetItr().first; it != m_obj_regist->GetItr().second;){
			(*it).second->isRemove() ? m_obj_regist->Erase(it++) : ++it;
		}
	}

	//　登録
	void Regist(const std::wstring name ,const std::shared_ptr<Object>obj){
		m_obj_regist->Regist(name, obj);
	}
};

