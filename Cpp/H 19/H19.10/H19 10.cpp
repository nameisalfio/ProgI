/* Definire una funzione che prende in input due array
monodimensionali di short v1 e v2 della stessa lunghezza. La
funzione restituisce un array di identica lunghezza in cui il generico
elemento di posto i contiene il numero max(v1[i],v2[i]).
*/

#include<iostream>
using namespace std;

short int* func(short int* , short int*, int);

int main(){
	
	int n;
	cout<<"Inserisci la lunghezza degli array : "<<endl;
	cin>>n;
	short int vet1 [n];
	short int vet2 [n];
	
    short int* vetmax = func (vet1, vet2, n);  //invocazione della funzione
    cout<<"Il vettore che contiene i valori massimi : "<<endl;
    
    //stampo il vettore
    for (int i=0; i<n; i++){
    	cout<<vetmax[i]<<" ";
	}
    

	return 0;
}

short int* func(short int *vet1, short int *vet2, int n){  //passaggio per riferimento
	
	//allocazione dinamica della memoria
	short int* vetp = new short int;
	
	//inserimento dei valori
	for(int i=0; i<n; i++){
		cout<<"Inserisci un valore nel primo array : "<<endl;
		cin>>vet1[i];
	}
	
	for(int i=0; i<n; i++){
		cout<<"Inserisci un valore nel secondo array : "<<endl;
		cin>>vet2[i];
	}
	
	//vettore massimo
	for(int i=0; i<n; i++){
		vetp[i] = (vet1[i] > vet2[i] ? vet1[i] : vet2[i]);
	}
	
	return vetp;  //restituisce il puntatore
	delete vetp;  //deallocazione
}