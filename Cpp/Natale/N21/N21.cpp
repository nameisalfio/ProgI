/*21.Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a.*/

#include <iostream>
#include <cmath>
using namespace std; 

bool func(double**D, int n, int a){
	double somma;
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n-1; i++){
			somma = (D[i][j]) + (D[i+1][j]);
			if(round(somma)==a){
				return true;
			}else{
				somma=0;
			}
		}
	}
	
	return false;
}

int main(){
	int n = 3;
	int a = 4;
	
	double **D = new double *[n];
	for(int i=0; i<n; i++){
		D[i] = new double [n];
		for(int j=0; j<n; j++){
			cout<<"Inserisci double : "<<endl;
			cin>>D[i][j];
		}
	}
	
	bool esito = func(D, n, a);
	if (esito)
	cout<<"Esiste";
	if(!esito)
	cout<<"Non esiste";
}