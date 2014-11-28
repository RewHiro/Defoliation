#pragma once
#include "../Scene.h"

class CResult :	public CScene{
public:
	CResult(std::shared_ptr<AppEnv>app_env);

	//　更新
	Type Update();

	//　描画
	void Draw();

private:

	struct number
	{
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

	//数字を配列で用意
	std::shared_ptr<number> numbers_info[10];

	//スコア
	int score8 = 0;

	int score77;


	//	プレイ前のスコアを記憶しておく
	int def_score1;
	int def_score2;
	int def_score3;
	int def_score4;
	int def_score5;
	int def_score6;
	int def_score7;
	int def_score8;
	int def_score11;
	int def_score22;
	int def_score33;
	int def_score44;
	int def_score55;
	int def_score66;
	int def_score77;

	//　操作
	void Control();
};

