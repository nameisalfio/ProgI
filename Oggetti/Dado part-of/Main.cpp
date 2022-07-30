/* Progettare e implementare una classe CoppiaDiDadi composta da due oggetti Dado a sei facce.
 Creare un file main.cpp che implementi una funzione main che tiri più volte l’oggetto
  CoppiaDiDadi contando il numero di doppi sei realizzati. */
  
#include "Dado.h"
#include <iostream>

using namespace std;

class coppia_dadi{
	private:
		int numero;
		Dado d1;
		Dado d2;
		
	public:
	    coppia_dadi();
	    int conta6 ();
};

coppia_dadi::coppia_dadi(){
}

int coppia_dadi::conta6(){
	for(int i=0; i<8; i++){
		d1.lancia();
		cout<<"\nLancio : "<<d1.get_faccia()<<endl;
		d2.lancia();
		cout<<"\nLancio : "<<d2.get_faccia()<<endl;
		if(d1.get_faccia() == 6 && d2.get_faccia() == 6){
			numero ++;
		}
	}
	return numero;
}

int main(){
	Dado d1;
	Dado d2;
	coppia_dadi coppia;
	cout<<"\nNumero di coppie di 6 : "<<coppia.conta6();
	
}