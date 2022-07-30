#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	
	cout<<" 10 NUMERI RANDOM DA 0 A 100 : "<<endl;

	for (int i = 0; i < 10; i++){
		
//    USANDO UNA VARIABILE
//	  pino = rand() % 101;
//	  cout<<pino<<endl;

      cout<< rand() % 101 <<endl;
      
	}
	
	cout<<"\n 10 NUMERI FLOAT COMPRESI TRA 0 e 10 : "<<endl;

	for (int i = 0; i < 10; i++){
		     
	  cout<< rand() * 10.0 / RAND_MAX<<endl;
//oppure 
//    cout<< (double) rand() * 10 / RAND_MAX<<endl;
	}
	
//	srand(time(0));  //generatore di numeri casuali
	                  //srand (time(NULL));
	                  
    //srand(111222333);  //generatore con seme 
	
	return 0;
	
}