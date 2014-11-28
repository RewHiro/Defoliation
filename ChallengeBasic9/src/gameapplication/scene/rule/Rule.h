#pragma once
#include "../Scene.h"

class CRule : public CScene{
public:
	CRule(std::shared_ptr<AppEnv>app_env);

	//　更新
	Type Update();

	//　描画
	void Draw();
};

