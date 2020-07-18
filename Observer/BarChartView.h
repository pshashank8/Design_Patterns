#pragma once
#include "Subscriber.h"
class DataManager ;
class BarChartView : public Subscriber
{
	DataManager *m_pMgr{} ;
public:
	BarChartView(DataManager* mPMgr)
		: m_pMgr{mPMgr} {
	}

	void Update(std::any  data) ;
};

