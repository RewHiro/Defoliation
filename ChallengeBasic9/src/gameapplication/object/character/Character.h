#pragma once
#include "../Object.h"
#include "../../resource/Resource.h"
#include "../../../lib/appEnv.hpp"

class CCharacter : public Object{
public:
	CCharacter():
		m_res(CResource::GetInstance()){}

protected:

	CResource& m_res;
};

