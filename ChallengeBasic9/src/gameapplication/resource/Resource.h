#pragma once
#include "../Uncopyable.h"
#include "../../lib/texture.hpp"
#include "../../lib/audio.hpp"
#include <memory>
#include <unordered_map>

//========================================
//リソースクラス
//========================================

class CResource : private Uncopyable{
public:
	//　インスタンスの取得
	static CResource& GetInstance(){
		static CResource instance;
		return instance;
	}

	enum class BG{
		TITLE,
		STAGE,
	};

	enum class BGM{
		TITLE,
		STAGE
	};

	enum class SE{
		BUTTON01,
		BUTTON02,
		STAGE_FINISH,
		STAGE_START,
		HIT01,
		HIT02
	};

	enum class Implant{
		HOLYGHOST,
		SWEETOPOTATO,
		SMOKE
	};

	enum class Enemy{
		HORNWORN,
		HORNWORN_DEATH,
	};

	enum class Player{
		PLAYER
	};

	enum class Obstacle{
		LEAF01,
		LEAF02,
		LEAF03,
		LEAF04,
	};

	enum class Result{
		NUM,
		TAPSWIPE_STRING,
		THOUSAND,
		FIVE_HUNDORED,
		COMBO,
		EQUAL,
		BY,
		SCORE,
		DIFF,
		TWO_HUNDRED_FIFTY
	};

	enum class Ranking{
		FIRST,
		SECOND,
		THIRD,
		YOUR
	};

	//　背景を取得
	Texture GetBG(const BG name)const{
		return m_bg.find(name)->second;
	}

	//　プレイヤーリソースを取得
	Texture GetPlayer(const Player name)const{
		return m_player.find(name)->second;
	}

	//　埋没物リソースを取得
	Texture GetImplant(const Implant name)const{
		return m_implant.find(name)->second;
	}

	//　エネミーリソースを取得
	Texture GetEnemy(const Enemy name)const{
		return m_enemy.find(name)->second;
	}

	//　障害物リソースを取得
	Texture GetObstacle(const Obstacle name)const{
		return m_obstacle.find(name)->second;
	}

	//　リザルトリソースを取得
	Texture GetResult(const Result name)const{
		return m_result.find(name)->second;
	}

	//　リザルトリソースを取得
	Texture GetRanking(const Ranking name)const{
		return m_ranking.find(name)->second;
	}

	//　BGMを取得
	std::shared_ptr<Media> GetBGM(const BGM name)const{
		return m_bgm.find(name)->second;
	}

	//　SEを取得
	std::shared_ptr<Media> GetSE(const SE name)const{
		return m_se.find(name)->second;
	}

private:
	CResource();
	std::unordered_map<BG, Texture>m_bg;								//　背景
	std::unordered_map<Player, Texture>m_player;								//　背景
	std::unordered_map<Implant, Texture>m_implant;								//　背景
	std::unordered_map<Enemy, Texture>m_enemy;								//　背景
	std::unordered_map<Obstacle, Texture>m_obstacle;								//　背景
	std::unordered_map<Result, Texture>m_result;								//　背景
	std::unordered_map<Ranking, Texture>m_ranking;								//　背景



	std::unordered_map<BGM, std::shared_ptr<Media>>m_bgm;				//　bgm
	std::unordered_map<SE, std::shared_ptr<Media>>m_se;				//　bgm


	//　背景の追加
	void RegistBG();

	//　BGMの追加
	void RegistBGM();

	//　SEの追加
	void RegistSE();

	//　プレイヤーの画像追加
	void RegistPlayer();

	//　埋没物の画像追加
	void RegistImplant();

	//　エネミーの画像取得
	void RegistEnemy();

	//　障害物の画像取得
	void RegistObstacle();

	//　リザルト画面の取得
	void RegistResult();

	//　ランキング画面の取得
	void RegistRanking();
};

typedef CResource::BG BG;
typedef CResource::BGM BGM;
typedef CResource::SE SE;
typedef CResource::Player PLAYER_GRAPH;
typedef CResource::Implant IMPLANT_GRAPH;
typedef CResource::Enemy ENEMY_GRAPH;
typedef CResource::Obstacle OBSTACLE_GRAPH;
typedef CResource::Result RESULT_GRAPH;
typedef CResource::Ranking RANKING_GRAPH;