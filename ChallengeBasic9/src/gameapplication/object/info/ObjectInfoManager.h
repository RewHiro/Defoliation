#pragma once
#include "ObjectInfo.h"

//========================================
//オブジェクトのデータ管理クラス
//========================================

class CObjectInfoManager{
public:
	CObjectInfoManager() = default;

	enum class Type{
		PLAYER,
		ENMEY,
		IMPLANT,
		OBSTACLE
	};



	//　登録
	CObjectInfoManager& operator()(const CObjectInfoManager::Type name){
		m_info_list.emplace(name, CObjectInfo());
		return *this;
	}

	//　クリア
	void Crear(){
		m_info_list.clear();
	}

	//　削除
	void Erase(const CObjectInfoManager::Type name){
		m_info_list.erase(name);
	}

	//　データを取得
	CObjectInfo& GetInfo(const Type name)const{ return m_info_list.find(name)->second; }
private:
	static std::unordered_map<Type, CObjectInfo>m_info_list;
};

typedef CObjectInfoManager::Type InfoType;