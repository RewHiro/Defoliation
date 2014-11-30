#pragma once
#include "../Uncopyable.h"
#include "../../lib/texture.hpp"
#include "../../lib/audio.hpp"
#include <memory>
#include <unordered_map>

//========================================
//���\�[�X�N���X
//========================================

class CResource : private Uncopyable{
public:
	//�@�C���X�^���X�̎擾
	static CResource& GetInstance(){
		static CResource instance;
		return instance;
	}

	enum class BG{
		TITLE,
		STAGE,
		RULE
	};

	enum class BGM{
		TITLE,
		STAGE,
		RESULT,
		RANKING
	};

	enum class SE{
		BUTTON01,
		BUTTON02,
		BUTTON03,
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

	//�@�w�i���擾
	Texture GetBG(const BG name)const{
		return m_bg.find(name)->second;
	}

	//�@�v���C���[���\�[�X���擾
	Texture GetPlayer(const Player name)const{
		return m_player.find(name)->second;
	}

	//�@���v�����\�[�X���擾
	Texture GetImplant(const Implant name)const{
		return m_implant.find(name)->second;
	}

	//�@�G�l�~�[���\�[�X���擾
	Texture GetEnemy(const Enemy name)const{
		return m_enemy.find(name)->second;
	}

	//�@��Q�����\�[�X���擾
	Texture GetObstacle(const Obstacle name)const{
		return m_obstacle.find(name)->second;
	}

	//�@���U���g���\�[�X���擾
	Texture GetResult(const Result name)const{
		return m_result.find(name)->second;
	}

	//�@���U���g���\�[�X���擾
	Texture GetRanking(const Ranking name)const{
		return m_ranking.find(name)->second;
	}

	//�@BGM���擾
	std::shared_ptr<Media> GetBGM(const BGM name)const{
		return m_bgm.find(name)->second;
	}

	//�@SE���擾
	std::shared_ptr<Media> GetSE(const SE name)const{
		return m_se.find(name)->second;
	}

private:
	CResource();
	std::unordered_map<BG, Texture>m_bg;								//�@�w�i
	std::unordered_map<Player, Texture>m_player;								//�@�w�i
	std::unordered_map<Implant, Texture>m_implant;								//�@�w�i
	std::unordered_map<Enemy, Texture>m_enemy;								//�@�w�i
	std::unordered_map<Obstacle, Texture>m_obstacle;								//�@�w�i
	std::unordered_map<Result, Texture>m_result;								//�@�w�i
	std::unordered_map<Ranking, Texture>m_ranking;								//�@�w�i



	std::unordered_map<BGM, std::shared_ptr<Media>>m_bgm;				//�@bgm
	std::unordered_map<SE, std::shared_ptr<Media>>m_se;				//�@bgm


	//�@�w�i�̒ǉ�
	void RegistBG();

	//�@BGM�̒ǉ�
	void RegistBGM();

	//�@SE�̒ǉ�
	void RegistSE();

	//�@�v���C���[�̉摜�ǉ�
	void RegistPlayer();

	//�@���v���̉摜�ǉ�
	void RegistImplant();

	//�@�G�l�~�[�̉摜�擾
	void RegistEnemy();

	//�@��Q���̉摜�擾
	void RegistObstacle();

	//�@���U���g��ʂ̎擾
	void RegistResult();

	//�@�����L���O��ʂ̎擾
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