#include "BarChartView.h"

#include <iostream>
#include "DataManager.h"

void BarChartView::Update(std::any  unused) {
	int data{};
	std::cout << "\nBarchart View\n" ;
	if (unused.has_value()) {
		/*if(typeid(int) == data.type()) {

		}*/
		auto index = std::any_cast<int>(unused);
		data = m_pMgr->Find(index) ;
		std::cout << data << "->";
		for (int j = 0; j < data; ++j) {
			std::cout << '#';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < m_pMgr->GetQuantity(); ++i) {
		data = m_pMgr->Find(i);
		std::cout << data;
		for (int j = 0; j < data; ++j) {
			std::cout << '#';
		}
		std::cout << '\n';
	}
	std::cout << '\n';

}
