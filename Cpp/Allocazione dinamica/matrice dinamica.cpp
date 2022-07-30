#include <iostream>

using namespace std;

int** fun(int **vet, int n, int m){
	
	vet = new int* [n];  //alloco dinamicamente l'array esterno
	
	for(int i=0; i<n; i++){
		vet[i] = new int [m];  //alloco dinamicamente l'array interno come di consuetudine
		
		for(int j=0; j<m; j++){
			cout<<"Inserisci un valore : "<<endl;
		    cin>> vet[i][j] ;
		}
	}    
	
	int **v = new int* [n];  //alloco dinamicamente l'array esterno
	
	for(int i=0; i<n; i++){
		v[i] = new int [m];  //alloco dinamicamente l'array interno come di consuetudine
		
		for(int j=0; j<m; j++){
			v[i][j] = 2 * vet[i][j];
		}
	}
	
	return v;
	delete [] v;	
}

int main(){
	
	int n, m;
	cout<<"Inserisci il numero di righe : "<<endl;
	cin>>n;
	cout<<"Inserisci il numero di colonne : "<<endl;
	cin>>m;
	
	int**vet ;
	vet = fun(vet, n, m);  //invocazione della funzione
	
	cout<<"La matrice doppia : "<<endl;
	
	for(int i=0; i<n; i++){  //stampo la matrice
		for(int j=0; j<m; j++){
			cout<<vet[i][j]<<" ";
		}
		cout<<endl;
	}
}