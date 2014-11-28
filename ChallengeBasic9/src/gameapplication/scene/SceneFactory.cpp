#include "SceneFactory.h"
#include "title\Title.h"
#include "stage\Stage.h"
#include "result\Result.h"
#include "rule\Rule.h"
#include "ranking\Ranking.h"

CSceneFactory::CSceneFactory(std::shared_ptr<AppEnv>app_env)
{
	m_scene_create_list.emplace(CScene::Type::TITLE, [app_env]{return std::make_unique<CTitle>(app_env); });
	m_scene_create_list.emplace(CScene::Type::STAGE, [app_env]{return std::make_unique<CStage>(app_env); });
	m_scene_create_list.emplace(CScene::Type::RESULT, [app_env]{return std::make_unique<CResult>(app_env); });
	m_scene_create_list.emplace(CScene::Type::RULE, [app_env]{return std::make_unique<CRule>(app_env); });
	m_scene_create_list.emplace(CScene::Type::RANKING, [app_env]{return std::make_unique<CRanking>(app_env); });
}