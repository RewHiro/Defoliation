#pragma once
#include "../Object.h"
#include "../../resource/Resource.h"
class CObstacle : public Object{
public:
	CObstacle() :
		m_res(CResource::GetInstance()){}
protected:
	CResource& m_res;
};

