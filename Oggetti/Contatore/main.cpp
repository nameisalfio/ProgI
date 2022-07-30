/* Realizza una classe 'contatore' che contiene una variabile intera 'valore' come attributo 
e due metodi, il primo è un costruttore senza parametri che inizializza 'valore' a 0 il secondo 
incrementa semplicemente 'valore ' di 1 tutte le volte che viene invocato. 
Esegui il test del programma con un ciclo for . */

#include <iostream>
using namespace std;

#include "Contatore.cpp"

int main() {
	
	Contatore c;
	cout<<"Incremento : "<<endl;
	for(int i=0; i<=5; i++){
		c.incrementa();
    }
    
    cout<<"\nDecremento : "<<endl;
    for(int i=0; i<=5; i++){
		c.decrementa();
    }


}
	

	
