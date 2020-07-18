#pragma once
#include <vector>
class DataManager ;
class TextView ;
class Application
{
	DataManager *m_pDm{} ;
	TextView *m_pTv{} ;
public:

	Application(DataManager* mPDm, TextView* mPTv);

	void Input() ;
	void Load() ;
	void Save() ;
};

