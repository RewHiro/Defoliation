#pragma once
#include "../Object.h"
#include "../../../lib/appEnv.hpp"
#include <unordered_map>

class CPlayerFactory{
public:

	enum class Type{
		PLAYER
	};

	CPlayerFactory(){
		m_object_create_list.emplace(Type::PLAYER, [](std::shared_ptr<AppEnv>app_env){return std::make_shared<CPlayer>(app_env); });
	}

	//　オブジェクトを取得
	std::shared_ptr<Object> Getobject(const Type name, std::shared_ptr<AppEnv>app_env)const{
		return (m_object_create_list.find(name)->second)(app_env);
	}

private:
	std::unordered_map < Type, std::function < std::shared_ptr<Object>(std::shared_ptr<AppEnv>) >> m_object_create_list;			//　シーン生成リスト
};

