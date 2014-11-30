#pragma once
#include "../factory/ScoreFactory.h"
#include "ObjectManager.h"

class CScoreManager : public CObjectManager{
public:
	CScoreManager();

	void Update();

	void Create();
private:
	CScoreFactory m_factory;
};

