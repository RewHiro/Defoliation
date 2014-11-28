#pragma once
#include <random>
#include <vector>

//=====================================
//ランダムクラス
//=====================================

class CRandom{
public:

	CRandom();

	static CRandom& GetInstance(){
		static CRandom instance;
		return instance;
	}

	//　シードの設定
	void SetSeed(const unsigned long seed);

	//　一様分布のランダム(実数)
	double Uniform(const double min, const double max);

	//　一様分布のランダム(実数)
	float Uniform(const float min, const float max);

	//　一様分布のランダム(整数)
	int Uniform(const int min, const int max);

	//　ベルヌーイ分布(指定した確率でtrueが出現、0.00~1.00)
	bool Bernulli(const float probability);

	//　正規分布
	//　exexpectation：期待値
	//　error：標準偏差(誤差)
	double Gaussian(const double expectation, const double error);

	int Gaussian(const int expectation, const int error);

	//　選択式
	int Select(const std::vector<int> &select);


private:
	std::mt19937 engine;
};