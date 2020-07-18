#include "DataManager.h"

#include <iostream>
#include <fstream>
#include "Subscriber.h"


void DataManager::Add(int data) {
	m_Data.push_back(data);
	Notify(NotificationType::Add,(int)(m_Data.size()-1));
}

int DataManager::Find(int index) const {
	return m_Data[index];
}

void DataManager::Modify(int index, int data) {
	m_Data[index] = data;
	Notify(NotificationType::Add,index);
}

void DataManager::Remove(int index) {
	m_Data.erase(begin(m_Data) + index);
	Notify(NotificationType::Remove,std::any{}) ;
}

int DataManager::GetQuantity() const {
	return m_Data.size();
}


void DataManager::Load() {
	std::ifstream input{ "data.txt" };
	if (!input) {
		std::cout << "Could not open the file for reading\n";
		return;
	}
	int data{};
	while (input >> data) {
		m_Data.push_back(data);
	}
	Notify(NotificationType::Add,std::any{}) ;
}

void DataManager::Save() {
	std::ofstream out{ "data.txt" };
	if (!out) {
		std::cout << "Could not open file for writing\n";
		return;
	}
	for (auto x : m_Data) {
		out << x << '\n';
	}
}


