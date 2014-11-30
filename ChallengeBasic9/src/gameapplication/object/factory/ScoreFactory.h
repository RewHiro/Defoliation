#pragma once
#include "../Object.h"
#include "../score/Score.h"
#include <unordered_map>
#include <functional>


class CScoreFactory{
public:

	enum class Type{
		PLUS_SCORE,
		MINUS_SCORE,
		PLUS_SCORE_TIME,
		MAINUS_SCORE_TIME,
	};

	CScoreFactory(){
		m_object_create_list01.emplace(Type::PLUS_SCORE, [](Vec2f& pos,int score){return std::make_shared<CScore>(pos,score,CScore::Type::PLUS_SCORE); });
		m_object_create_list01.emplace(Type::MINUS_SCORE, [](Vec2f& pos, int score){return std::make_shared<CScore>(pos, score, CScore::Type::MINUS_SCORE); });
		m_object_create_list02.emplace(Type::PLUS_SCORE_TIME, [](Vec2f& pos, int score, std::chrono::seconds& time){return std::make_shared<CScore>(pos, score,time,CScore::Type::PLUS_SCORE_TIME); });
		m_object_create_list02.emplace(Type::MAINUS_SCORE_TIME, [](Vec2f& pos, int score, std::chrono::seconds& time){return std::make_shared<CScore>(pos, score, time,CScore::Type::MAINUS_SCORE_TIME); });
	}

	//　オブジェクトを取得
	std::shared_ptr<Object> Getobject(const Type name, Vec2f& pos, int score)const{
		return (m_object_create_list01.find(name)->second)(pos,score);
	}

	//　オブジェクトを取得
	std::shared_ptr<Object> Getobject(const Type name, Vec2f& pos, int score,std::chrono::seconds& time)const{
		return (m_object_create_list02.find(name)->second)(pos, score, time);
	}

private:
	std::unordered_map < Type, std::function < std::shared_ptr<Object>(Vec2f,int) >> m_object_create_list01;			//　シーン生成リスト
	std::unordered_map < Type, std::function < std::shared_ptr<Object>(Vec2f, int, std::chrono::seconds& time) >> m_object_create_list02;			//　シーン生成リスト
};

