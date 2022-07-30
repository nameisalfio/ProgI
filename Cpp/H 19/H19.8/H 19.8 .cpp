/*Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte il valore massimo
con il valore minimo. 
ES: [ 1 2 6 4 5 ] −− > [ 6 2 1 4 5 ].*/

#include <iostream>
using namespace std;

int func (int* vet, int n){
	
	int max,min;
	int *pvet = new int[n];
	int *ptrmax = &max;
	int *ptrmin = &min;
	
//	int *ptr= vet;  //assegno il primo valore dell'array//
	
	for (int i=0; i<n; i++){
		
		cout<<"Inserisci valore nell'array : "<<endl;
		cin>>vet[i];
    }
    
	for (int i=0; i<n; i++){
		
		max = vet[i];
		min = vet[i];
	
	    max = vet[i]>max ? vet[i] : max;
	    min = vet[i]<min ? vet[i] : min;
	    
	    *ptrmax = min;  //modifico il valore puntato dal puntatore
	    cout<<*ptrmax<<endl;
	    cout<<max<<endl;
	    
	    *ptrmin = max;
	    cout<<*ptrmin<<endl;
	    cout<<min<<endl;
	    
	     pvet = &vet[i];  //assegno l'indirizzo di vet[i]
	     cout<<pvet<<endl;
	     
	     return pvet;  //ritorno l'indirizzo di vet[i]  //ritorno il valore di vet[i]
	}
	delete *pvet;
}

int main(){
	int n;
	cout<<"Inserisci la dimensione dell'array : "<<endl;
	cin>>n;
	int vet[n];
	
	int *array = func (vet, n);
	cout<<"Il vettore scambiato e' : "<<array<<endl;
}