#include "Ranking.h"
#include "../../../lib/utils.hpp"
#include <fstream>

const int NAME_POS_X = 250;

CRanking::CRanking(std::shared_ptr<AppEnv>app_env) :
CScene(app_env)
{
	for (auto& Score : score){
		Score = 0;
	}

	numbers_info[0] = number(0, Vec2f(0, 0), Vec2f(32, 64), Vec2f(16, 32), Vec2f(25, 32));
	numbers_info[1] = number(1, Vec2f(0, 0), Vec2f(32, 64), Vec2f(36, 32), Vec2f(22, 32));
	numbers_info[2] = number(2, Vec2f(0, 0), Vec2f(32, 64), Vec2f(56, 32), Vec2f(22, 32));
	numbers_info[3] = number(3, Vec2f(0, 0), Vec2f(32, 64), Vec2f(76, 32), Vec2f(22, 32));
	numbers_info[4] = number(4, Vec2f(0, 0), Vec2f(32, 64), Vec2f(96, 32), Vec2f(25, 32));
	numbers_info[5] = number(5, Vec2f(0, 0), Vec2f(32, 64), Vec2f(136, 32), Vec2f(24, 32));
	numbers_info[6] = number(6, Vec2f(0, 0), Vec2f(32, 64), Vec2f(156, 32), Vec2f(23, 32));
	numbers_info[7] = number(7, Vec2f(0, 0), Vec2f(32, 64), Vec2f(178, 32), Vec2f(23, 32));
	numbers_info[8] = number(8, Vec2f(0, 0), Vec2f(32, 64), Vec2f(198, 32), Vec2f(23, 32));
	numbers_info[9] = number(9, Vec2f(0, 0), Vec2f(32, 64), Vec2f(220, 32), Vec2f(25, 32));

	std::ifstream fstr("res/score_ranking.txt");
	if (fstr) {
		for (int i = 0; i < 3; ++i) {
			fstr >> score[i];
		}
	}
	std::ifstream load("res/now_score.txt");
	if (load){
		load >> score[3];
	}
	def_score4 = score[3];
	m_change_scene = Type::RANKING;

	std::ifstream your_name("res/your_name.txt");
	if (your_name){
		your_name >> m_str_name[3];
	}

	std::ifstream ranking_name("res/ranking_name.txt");
	if (ranking_name){
		for (int i = 0; i < 3; i++){
			ranking_name >> m_str_name[i];
		}
	}



	while (1) {
		bool swaped = false;

		for (int i = 0; i < (elemsof(score) - 1); ++i) {
			if (score[i] < score[i + 1]) {
				std::swap(score[i], score[i + 1]);
				std::swap(m_str_name[i], m_str_name[i + 1]);
				swaped = true;
			}
		}
		if (!swaped) break;
	}

	def_score1 = score[0];
	def_score2 = score[1];
	def_score3 = score[2];
	m_res.GetBGM(BGM::RANKING)->looping(true);
	m_res.GetBGM(BGM::RANKING)->play();


	std::ifstream your("res/your_name.txt");
	if (your){
		your >> m_str_name[3];
	}


	for (auto& name : m_name){
		name = std::make_unique<Font>(40);
	}

}

//　更新
CScene::Type CRanking::Update(){
	Control();

	return m_change_scene;
}

//　描画
void CRanking::Draw(){
	//背景
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
		0, 0, 1024, 512,
		m_res.GetBG(BG::STAGE),
		Color(1, 1, 1));

	//1位スコア
	int one_points1 = def_score1 / 1 % 10;
	int ten_points1 = def_score1 / 10 % 10;
	int hundred_points1 = def_score1 / 100 % 10;
	int thousand_points1 = def_score1 / 1000 % 10;
	int ten_thousand_points1 = def_score1 / 10000;
	//１位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points1 == numbers_info[i].id){
			drawTextureBox(-50, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_points1 == numbers_info[i].id){
			drawTextureBox(-75, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (hundred_points1 == numbers_info[i].id){
			drawTextureBox(-100, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (thousand_points1 == numbers_info[i].id){
			drawTextureBox(-125, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_thousand_points1 == numbers_info[i].id){
			drawTextureBox(-150, 180, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
	}

	m_name[0]->Draw(m_str_name[0], NAME_POS_X, 180, Color(0, 0, 0));

	//２位元スコア
	int one_points2 = def_score2 / 1 % 10;
	int ten_points2 = def_score2 / 10 % 10;
	int hundred_points2 = def_score2 / 100 % 10;
	int thousand_points2 = def_score2 / 1000 % 10;
	int ten_thousand_points2 = def_score2 / 10000;
	//２位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points2 == numbers_info[i].id){
			drawTextureBox(-50, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_points2 == numbers_info[i].id){
			drawTextureBox(-75, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (hundred_points2 == numbers_info[i].id){
			drawTextureBox(-100, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (thousand_points2 == numbers_info[i].id){
			drawTextureBox(-125, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_thousand_points2 == numbers_info[i].id){
			drawTextureBox(-150, 50, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
	}

	m_name[1]->Draw(m_str_name[1], NAME_POS_X, 50, Color(0, 0, 0));

	//３位元スコア
	int one_points3 = def_score3 / 1 % 10;
	int ten_points3 = def_score3 / 10 % 10;
	int hundred_points3 = def_score3 / 100 % 10;
	int thousand_points3 = def_score3 / 1000 % 10;
	int ten_thousand_points3 = def_score3 / 10000;
	//３位変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points3 == numbers_info[i].id){
			drawTextureBox(-50, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_points3 == numbers_info[i].id){
			drawTextureBox(-75, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (hundred_points3 == numbers_info[i].id){
			drawTextureBox(-100, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (thousand_points3 == numbers_info[i].id){
			drawTextureBox(-125, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_thousand_points3 == numbers_info[i].id){
			drawTextureBox(-150, -80, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
	}

	m_name[2]->Draw(m_str_name[2], NAME_POS_X, -80, Color(0, 0, 0));

	//貴方の元スコア
	int one_points4 = def_score4 / 1 % 10;
	int ten_points4 = def_score4 / 10 % 10;
	int hundred_points4 = def_score4 / 100 % 10;
	int thousand_points4 = def_score4 / 1000 % 10;
	int ten_thousand_points4 = def_score4 / 10000;
	//貴方の変動スコア
	for (int i = 0; i < 10; i++){
		if (one_points4 == numbers_info[i].id){
			drawTextureBox(-50, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_points4 == numbers_info[i].id){
			drawTextureBox(-75, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (hundred_points4 == numbers_info[i].id){
			drawTextureBox(-100, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (thousand_points4 == numbers_info[i].id){
			drawTextureBox(-125, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
		if (ten_thousand_points4 == numbers_info[i].id){
			drawTextureBox(-150, -210, 32, 32, numbers_info[i].texture_pos.x(), numbers_info[i].texture_pos.y(), numbers_info[i].texture_size.x(), numbers_info[i].texture_size.y(), m_res.GetResult(RESULT_GRAPH::NUM), Color(1, 1, 1));
		}
	}

	m_name[3]->Draw(m_str_name[3], NAME_POS_X, -210, Color(0, 0, 0));

	//１位
	drawTextureBox(-400, 160, 128, 64, 0, 0, 128, 64,
		m_res.GetRanking(RANKING_GRAPH::FIRST),
		Color(1, 1, 1));
	//２位
	drawTextureBox(-400, 30, 128, 64, 0, 0, 128, 64,
		m_res.GetRanking(RANKING_GRAPH::SECOND),
		Color(1, 1, 1));
	//３位
	drawTextureBox(-400, -100, 128, 64, 0, 0, 128, 64,
		m_res.GetRanking(RANKING_GRAPH::THIRD),
		Color(1, 1, 1));
	//貴方のスコア
	drawTextureBox(-450, -230, 256, 64, 0, 0, 256, 64,
		m_res.GetRanking(RANKING_GRAPH::YOUR),
		Color(1, 1, 1));






}

//　操作
void CRanking::Control(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_change_scene = Type::TITLE;
		std::ofstream save("res/score_ranking.txt");
		if (save){
			save << score[0] << std::endl
				<< score[1] << std::endl
				<< score[2];
		}
		m_res.GetBGM(BGM::RANKING)->stop();
	}
}