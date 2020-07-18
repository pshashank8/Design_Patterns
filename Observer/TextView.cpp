#include "TextView.h"

#include <iostream>
#include "DataManager.h"
void TextView::Update(std::any data) {
	if (data.has_value()) {
		/*if(typeid(int) == data.type()) {

		}*/
		auto index = std::any_cast<int>(data);
		std::cout << m_pMgr->Find(index) << '\n';
		return;
	}

	for (int i = 0; i < m_pMgr->GetQuantity(); ++i) {
		std::cout << m_pMgr->Find(i) << ' ';
	}
}
