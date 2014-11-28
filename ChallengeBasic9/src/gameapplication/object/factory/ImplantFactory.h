#pragma once
#include "../Object.h"
#include "../implant/holyghost/HolyGhost.h"
#include "../implant/sweetpotato/SweetoPotato.h"
#include <unordered_map>
#include <functional>


class CImplantFactory{
public:

	enum class Type{
		HOLYGHOST,
		SWEETOPOTAO
	};

	CImplantFactory(){
		m_object_create_list.emplace(Type::HOLYGHOST, [](){return std::make_shared<CHolyGhost>(); });
		m_object_create_list.emplace(Type::SWEETOPOTAO, [](){return std::make_shared<CSweetoPotato>(); });
	}



	//　オブジェクトを取得
	std::shared_ptr<Object> Getobject(const Type name)const{
		return (m_object_create_list.find(name)->second)();
	}

private:
	std::unordered_map < Type, std::function < std::shared_ptr<Object>() >> m_object_create_list;			//　シーン生成リスト
};

