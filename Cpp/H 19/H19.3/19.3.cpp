/*Definire una funzione che prende in input un array
monodimensionale di double e restituisce l’arrotondamento
all’intero più vicino della somma degli elementi dello array.
*/

#include<iostream>
#include<cmath>

using namespace std;

int arrotondamento (double* , int);  //prototipo

int main (){
	
    int n;
	cout<<"Inserisci la dimensione : "<<endl;
	cin>>n;
	
	double vet[n];
	
	cout<<endl<<arrotondamento (vet, n) ; //richiamo la funzione
	
	return 0;
}


int arrotondamento (double* vet , int n){
	double somma = 0.0;
	int r ;
	
	for (int i=0; i<n; i++){  //inserisco valori nell'array
	
		cout<<"inserisci un valore nell'array : "<<endl;
		cin>>vet[i];
		
		somma = somma+vet[i];
		
	}
	
	for (int i =0; i<n; i++){  //stampo l'array
		cout<<vet[i]<<"  ";
	}
	
	r = round(somma);
	
    return r;
}




