#pragma once
#include "../Object.h"
#include "../../resource/Resource.h"

class CImplant : public Object{
public:
	CImplant() :
		m_res(CResource::GetInstance()),
		m_alpha(0){}
	bool GetisScore(){ return m_is_score; }
protected:
	CResource& m_res;
	int m_alpha;
	bool m_is_score = false;
};

