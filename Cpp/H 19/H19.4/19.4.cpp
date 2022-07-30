/*Definire una funzione che prende in input un array
monodimensionale di interi senza segno e restituisce la media degli
elementi di tale array.
*/

#include <iostream>

using namespace std;

 float media (unsigned *, int);

int main(){
	
	int n;
	cout<<"Inserisci la dimensione : "<<endl;
	cin>>n;
	
	unsigned vet [n];
	
	for (int i=0; i<n; i++){
		
		cout<<"Inserisci un valore nell'array : "<<endl;
		cin>>vet[i];
	
	}
	
	cout<<"La media e' : "<<media(vet, n)<<endl;
	
	return 0;
	
}

float media (unsigned *vet, int n){  //dichiarazione della funzione 
	
	unsigned int somma = 0;
	double avr;
	
	for (int i=0; i<n; i++){
		somma = somma + vet[i];
	}
	
	avr = somma/n;
	return avr;
}




