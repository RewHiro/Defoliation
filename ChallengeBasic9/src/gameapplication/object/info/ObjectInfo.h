#pragma once
#include "../regist/ObjectRegist.h"

//========================================
//オブジェクトのデータクラス
//========================================

class CObjectInfo{
	typedef std::unordered_multimap < std::wstring, std::shared_ptr<Object>>::iterator ObjMapIt;
public:
	CObjectInfo() = default;

	//　登録
	void Regist(const std::shared_ptr<CObjectRegist>obj_regist){
		m_obj_regist = obj_regist;
	}
	
	//　オブジェクトを取得
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> Getobject()const{
		return m_obj_regist.lock()->Getobject();
	}

	//　最初と最後のイテレーターを返す
	std::pair<ObjMapIt, ObjMapIt> GetItr()const{
		return m_obj_regist.lock()->GetItr();
	}
	std::pair<ObjMapIt, ObjMapIt> GetItr(std::wstring name)const{
		return m_obj_regist.lock()->GetItr(name);
	}

	//　最初のイテレーターを返す
	ObjMapIt Begin(const std::wstring name)const{
		return GetItr(name).first;
	}
	ObjMapIt Begin()const{
		return GetItr().first;
	}

	//　最初のイテレーターを返す
	ObjMapIt End()const{
		return GetItr().second;
	}
	ObjMapIt End(const std::wstring name)const{
		return GetItr(name).second;
	}

	//　ポジションを取得
	Vec2f GetPos(const ObjMapIt itr)const{
		return itr->second->GetPos();
	}

	//　大きさを取得
	Vec2f GetScale(const ObjMapIt itr)const{
		return itr->second->GetScale();
	}

	//　アクティブかを取得
	bool GetActive(const ObjMapIt itr)const{
		return itr->second->isActive();
	}

	void Death(const ObjMapIt itr){
		itr->second->Death();
	}

	//　ダウンキャスト
	template <class Type>
	std::shared_ptr<Type> DynamicCast(const ObjMapIt itr)const{
		return std::dynamic_pointer_cast<Type>(itr->second);
	}

	//　空か取得
	bool GetEmpty()const{
		return m_obj_regist.lock()->Getobject().empty();
	}

	//　要素数の取得
	int GetCount()const{
		return m_obj_regist.lock()->Getobject().size();
	}

	//　要素数を取得
	int GetCount(const std::wstring name){
		int count = 0;
		for (auto it = GetItr(name).first; it != GetItr(name).second; it++){
			count++;
		}
		return count;
	}

private:
	std::weak_ptr<CObjectRegist>m_obj_regist;
};

