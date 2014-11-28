#pragma once
#include "../lib/appEnv.hpp"

//========================================
//コピー禁止クラス
//========================================

class Uncopyable{
public:
protected:
	Uncopyable() = default;
private:
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable &operator=(const Uncopyable&) = delete;

	Uncopyable(const Uncopyable&(AppEnv)) = delete;
	Uncopyable &operator=(const Uncopyable&(AppEnv)) = delete;
};