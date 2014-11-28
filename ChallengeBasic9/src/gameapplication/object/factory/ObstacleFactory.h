#pragma once
#include "../Object.h"
#include "../obstacle/leaf/Leaf.h"
#include <unordered_map>
#include <functional>


class CObstacleFactory{
public:

	enum class Type{
		LEAF
	};

	CObstacleFactory(){
		m_object_create_list.emplace(Type::LEAF, [](){return std::make_shared<CLeaf>(); });
	}

	//　オブジェクトを取得
	std::shared_ptr<Object> Getobject(const Type name)const{
		return (m_object_create_list.find(name)->second)();
	}

private:
	std::unordered_map < Type, std::function < std::shared_ptr<Object>() >> m_object_create_list;			//　シーン生成リスト
};

