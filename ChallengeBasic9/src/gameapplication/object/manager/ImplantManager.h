#pragma once
#include "ObjectManager.h"
#include "../factory/ImplantFactory.h"

class CImplantManager : public CObjectManager{
public:
	CImplantManager();

	void Update();
private:
	CImplantFactory m_factory;

	void Create();
};

