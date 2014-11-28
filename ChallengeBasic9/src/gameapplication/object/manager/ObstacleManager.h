#pragma once
#include "../factory/ObstacleFactory.h"
#include "ObjectManager.h"

class CObstacleManager : public CObjectManager{
public:
	CObstacleManager();
private:
	CObstacleFactory m_factory;
};

