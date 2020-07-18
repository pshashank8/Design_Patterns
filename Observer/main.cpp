#include <iostream>

#include "Application.h"
#include "TextView.h"
#include "DataManager.h"
#include "BarChartView.h"
int main() {
	DataManager mgr ;
	TextView tv{&mgr} ;
	
	//Application app{&mgr, &tv} ;
	//app.Input() ;
	//app.Save() ;
	//app.Load() ;
	mgr.Register(NotificationType::Add,&tv) ;
	mgr.Load() ;
	BarChartView bv{&mgr} ;
	mgr.Register(NotificationType::Remove, &bv) ;
	std::cout << "\nAdding new data : " ;
	mgr.Add(3) ;

	//mgr.Notify(std::any{}) ;
	/*std::cout << "\nRemoving data : " ;
	mgr.Remove(0) ;*/
}
