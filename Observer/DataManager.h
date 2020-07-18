#pragma once
#include <list>
#include <vector>


#include "Publisher.h"
#include "TextView.h"
class Subscriber ;
class DataManager : public Publisher
{
	std::vector<int> m_Data{} ;
public:
	void Add(int data) ;
	int Find(int index)const ;
	void Modify(int index, int data) ;
	void Remove(int index) ;
	int GetQuantity()const ;
	void Load() ;
	void Save() ;
};

