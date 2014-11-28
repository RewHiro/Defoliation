#pragma once
#include "../Character.h"
#include "../../info/ObjectInfoManager.h"
#include <unordered_map>
#include <string>

class CEnemy : public CCharacter{
public:
	CEnemy() = default;


protected:
	CObjectInfoManager m_info;
};

