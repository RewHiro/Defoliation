#pragma once
#include "../Object.h"
#include <unordered_map>
#include <string>

//========================================
//オブジェクトの登録クラス
//========================================

class CObjectRegist{
	typedef std::unordered_multimap < std::wstring, std::shared_ptr<Object>>::iterator ObjMapIt;
public:
	CObjectRegist() = default;

	//　登録
	void Regist(const std::wstring name, const std::shared_ptr<Object>obj){
		m_obj_list.emplace(name, obj);
	}

	//　オブジェクトの取得
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> Getobject()const{ return m_obj_list; }

	//　最初と最後のイテレーターを返す
	std::pair<ObjMapIt, ObjMapIt> GetItr(){
		return std::make_pair(m_obj_list.begin(), m_obj_list.end());
	}

	//　指定した範囲を取得
	std::pair<ObjMapIt, ObjMapIt> GetItr(const std::wstring name){
		return m_obj_list.equal_range(name);
	}

	//　空か取得
	bool GetEmpty()const{
		return m_obj_list.empty();
	}

	//　要素数を取得
	int GetCount()const{
		return m_obj_list.size();
	}

	//　削除
	void Erase(const ObjMapIt it){ m_obj_list.erase(it); }

protected:
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> m_obj_list;
};

