#pragma once
#include <vector>

#include "Subscriber.h"
class DataManager ;
class TextView : public Subscriber
{
	DataManager *m_pMgr{} ;
public:
	TextView(DataManager* mPMgr)
		: m_pMgr{mPMgr} {
	}
	void Update(std::any  data) ;
};

