#include <iostream>
#include <ctime>

class Dado {
  	
  	private :
  		int faccia;
  	public :
  		Dado();
  		void lancia();
  		int get_faccia();
  		
};
  
Dado::Dado(){  //COSTRUTTORE
	
}

void Dado::lancia(){
	short a = 1;
	short b = 6;
	srand(time(NULL));
	faccia = rand() % (b-a+1)+a;
	
}

int Dado::get_faccia(){
	return faccia;
}