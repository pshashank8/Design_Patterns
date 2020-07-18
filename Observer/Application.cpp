#include "Application.h"

#include <iostream>
#include <fstream>
#include "DataManager.h"
#include "TextView.h"
Application::Application(DataManager* mPDm, TextView* mPTv): m_pDm{mPDm},
                                                             m_pTv{mPTv} {
}



void Application::Input() {
	int data{} ;
	std::cout <<"Enter numbers:" ;
	for(int i = 0 ; i < 3 ; ++i) {
		std::cin >> data ;
		m_pDm->Add(data) ;
	}
}


void Application::Load() {
	m_pDm->Load() ;
	for(int i = 0 ; i < m_pDm->GetQuantity() ; ++i)
		m_pTv->Update(m_pDm->Find(i)) ;
	
}

void Application::Save() {
	m_pDm->Save() ;
}
