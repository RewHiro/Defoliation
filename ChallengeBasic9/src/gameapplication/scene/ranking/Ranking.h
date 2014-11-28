#pragma once
#include "../Scene.h"

// ランキング数をenumで定義
enum { RANKING_NUM = 4 };

class CRanking : public CScene{
public:
	CRanking(std::shared_ptr<AppEnv>app_env);
	
	struct number
	{
		number() = default;
		number(int id, Vec2f& pos, Vec2f& size, Vec2f& texture_pos, Vec2f& texture_size) :
			id(id),
			pos(pos),
			size(size),
			texture_pos(texture_pos),
			texture_size(texture_size){}

		int id;
		Vec2f pos;
		Vec2f size;
		Vec2f texture_pos;
		Vec2f texture_size;

	};

	number numbers_info[10];

	// 初期値は「0」
	int score[4];
	//スコア
	int score1 = 40000;
	int score2 = 30000;
	int score3 = 20000;
	int score4 = 10000;

	//プレイ前のスコア記憶
	int def_score1;
	int def_score2;
	int def_score3;
	int def_score4;

	//　更新
	Type Update();

	//　描画
	void Draw();
private:
	float angle = 0.0;


	//　操作
	void Control();

};

