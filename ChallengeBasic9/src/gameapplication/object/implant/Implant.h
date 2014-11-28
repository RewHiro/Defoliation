#pragma once
#include "../Object.h"
#include "../../resource/Resource.h"

class CImplant : public Object{
public:
	CImplant() :
		m_res(CResource::GetInstance()),
		m_alpha(0){}

protected:
	CResource& m_res;
	int m_alpha;
};

