#include "Resource.h"

CResource::CResource()
{
	RegistBG();
	RegistBGM();
	RegistSE();
	RegistPlayer();
	RegistImplant();
	RegistEnemy();
	RegistObstacle();
	RegistResult();
	RegistRanking();
}

//Å@îwåiÇÃí«â¡
void CResource::RegistBG(){
	m_bg.emplace(BG::TITLE, Texture("res/graph/title_graph.png"));
	m_bg.emplace(BG::STAGE, Texture("res/graph/stage_graph.png"));
}

//Å@BGMÇÃí«â¡
void CResource::RegistBGM(){
	m_bgm.emplace(BGM::TITLE, std::make_shared<Media>("res/sound/title_bg.wav"));
	m_bgm.emplace(BGM::STAGE, std::make_shared<Media>("res/sound/stage_bg.wav"));
}

void CResource::RegistSE(){
	m_se.emplace(SE::BUTTON01, std::make_shared<Media>("res/sound/title_button01.wav"));
	m_se.emplace(SE::BUTTON02, std::make_shared<Media>("res/sound/title_button02.wav"));
	m_se.emplace(SE::STAGE_FINISH, std::make_shared<Media>("res/sound/finish.wav"));
	m_se.emplace(SE::STAGE_START, std::make_shared<Media>("res/sound/start.wav"));
	m_se.emplace(SE::HIT01, std::make_shared<Media>("res/sound/hit01.wav"));
	m_se.emplace(SE::HIT02, std::make_shared<Media>("res/sound/hit02.wav"));
}

void CResource::RegistPlayer(){
	m_player.emplace(Player::PLAYER, Texture("res/graph/player/player.png"));
}

void CResource::RegistImplant(){
	m_implant.emplace(Implant::HOLYGHOST, Texture("res/graph/holyghost/holyghost.png"));
	m_implant.emplace(Implant::SWEETOPOTATO, Texture("res/graph/item/sweet_potato.png"));
	m_implant.emplace(Implant::SMOKE, Texture("res/graph/item/smoke.png"));
}

void CResource::RegistEnemy(){
	m_enemy.emplace(Enemy::HORNWORN, Texture("res/graph/enemy/enemy.png"));
	m_enemy.emplace(Enemy::HORNWORN_DEATH, Texture("res/graph/enemy/death.png"));
}

void CResource::RegistObstacle(){
	m_obstacle.emplace(Obstacle::LEAF01, Texture("res/1.png"));
	m_obstacle.emplace(Obstacle::LEAF02, Texture("res/2.png"));
	m_obstacle.emplace(Obstacle::LEAF03, Texture("res/3.png"));
	m_obstacle.emplace(Obstacle::LEAF04, Texture("res/4.png"));
}

void CResource::RegistResult(){
	m_result.emplace(Result::BY, Texture("res/kakeru.png"));

	m_result.emplace(Result::COMBO, Texture("res/combo.png"));

	m_result.emplace(Result::EQUAL, Texture("res/iko_ru.png"));

	m_result.emplace(Result::FIVE_HUNDORED, Texture("res/five_hundred.png"));

	m_result.emplace(Result::NUM, Texture("res/number.png"));

	m_result.emplace(Result::TAPSWIPE_STRING, Texture("res/tap_swipe.png"));
	m_result.emplace(Result::THOUSAND, Texture("res/thousand.png"));
	m_result.emplace(Result::SCORE, Texture("res/resultscore.png"));
	m_result.emplace(Result::DIFF, Texture("res/mainasu.png"));
	m_result.emplace(Result::TWO_HUNDRED_FIFTY, Texture("res/two hundred fifty .png"));
}

void CResource::RegistRanking(){
	m_ranking.emplace(Ranking::FIRST, Texture("res/first.png"));
	m_ranking.emplace(Ranking::SECOND, Texture("res/second.png"));
	m_ranking.emplace(Ranking::THIRD, Texture("res/third.png"));
	m_ranking.emplace(Ranking::YOUR, Texture("res/your_score.png"));
}