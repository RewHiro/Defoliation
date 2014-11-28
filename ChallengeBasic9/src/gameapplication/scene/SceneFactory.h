#pragma once
#include "Scene.h"
#include <unordered_map>

//========================================
//シーンファクトリークラス
//========================================

class CSceneFactory{
public:
	CSceneFactory(std::shared_ptr<AppEnv>app_env);

	//　シーンを取得
	std::unique_ptr<CScene> GetScene(const CScene::Type type)const{
		return std::move((m_scene_create_list.find(type)->second)());
	};

private:
	std::unordered_map < CScene::Type, std::function < std::unique_ptr<CScene> () >> m_scene_create_list;			//　シーン生成リスト
};